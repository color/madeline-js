#include <iostream>
#include "DataTable.h"
#include "Database.h"

#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <fstream>
#include <sstream>

/*!
 *
 * The Parser class is used to read files into a DataTables.
 * The parser can read in 3 types of file: Local files, Network files, and Mysql files.
 *
 * When the Parser class reads in a file, it first attempts to uncompress it.
 * Compression types that are supported are GZIP, PKZIP, and BZIP2.
 * Then, it attempts to parse the file. Parsable formats are:
 *
 *  1. Madeline flat file format
 *  2. Delimited format
 *  3. OASIS XML
 *  4. XHTML XML
 *  5. Madeline XML
 *  5. Microsoft's Excel XML format
 *
 * After parsing the file, table data in the file are put into a DataTables.
 * Multiple tables in one file are supported for some formats, such as OASIS and
 * XHTML XML files.
 *
*/
class Parser
{

private:

	std::string _fileName;                      // fileName for disk file (also for network local /tmp file)

	std::vector<DataTable *> _tables;            // List of all data tables that have been read in

	//
	// FileTypeClassifier _fileTypeClassifier;     // The FileTypeClassifier class opens files to determine their type.
	//
	FileTypeClassifier::FILE_TYPE _fileType;
	const char* _fileTypeName;

	#ifdef MYSQLPP
	Database _currentMysqlTable;
	#endif

	// Read file based on type
	void _readDelimited(std::string data);
	void _readMadeline(std::string data);

	// Used to determine format of flat files
	int _determineNumberOfBlocks(std::string inString);

	// Used to convert a file into a string
	std::string _stringify(std::string name);

public:

	Parser();
	~Parser();
	void display();                                     /// Prints out all datatables that have been read in


    void from_string(std::vector<std::string> const &header,
                     std::vector<std::string> const &content);


	void readFile(const std::string &filename);        /// Read in a file, unzip it, parse it, and put the contents into a datatable

	#ifdef MYSQLPP
	void readMysql(std::string tableName);                  /// Read in a Mysql table, and put the contents into a datatable
	void connectMysql(std::string host,std::string port, std::string user, std::string password, std::string database);  /// connect to a mysql table for reading/queries
	void queryMysql(const char* sqlQuery) {_currentMysqlTable.query(sqlQuery);} /// query a mysql table with a select, insert, delete, or update command
	#endif

	DataTable * getTable(unsigned i) { return _tables[i];}      /// returns a specific datatable


	const int getNumberOfTables( void ) const { return _tables.size(); };

	std::string getName(void) const { return _fileName; };

};
