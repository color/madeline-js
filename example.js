var Madeline = require('./madeline.js');

var individuals = [
  {
    IndividualId: 'm100',
    Familyid: 'test',
    Name: 'm100',
    Gender: 'f',
    Affected: 'a'
  }, {
    IndividualId: 'm101',
    Familyid: 'test',
    Name: 'John Doe',
    Gender: 'm',
    Affected: 'b'
  }, {
    IndividualId: 'm102',
    Familyid: 'test',
    Name: 'm102',
    Gender: 'f',
    Affected: 'c'
  }, {
    IndividualId: 'm103',
    Familyid: 'test',
    Name: 'm103',
    Mother: 'm100',
    Father: 'm101',
    MZTwin: 'test',
    Affected: 'a'
  }, {
    IndividualId: 'm104',
    Familyid: 'test',
    Name: 'm104',
    Gender: 'f',
    Mother: 'm102',
    Father: 'm101',
    Affected: 'b'
  }, {
    IndividualId: 'm105',
    Familyid: 'test',
    Name: 'm105',
    Mother: 'm100',
    Father: 'm101',
    MZTwin: 'test',
    Affected: 'c'
  }, {
    IndividualId: 'm106',
    Familyid: 'test',
    Gender: 'm',
  }, {
    IndividualId: 'm107',
    Familyid: 'test',
    Name: 'm107',
    Mother: 'm104',
    Father: 'm106',
    DZTwin: 'rest',
    Affected: 'a'
  }, {
    IndividualId: 'm108',
    Familyid: 'test',
    Name: 'm108',
    Mother: 'm104',
    Father: 'm106',
    DZTwin: 'rest',
    DOB: '12/12/12',
    Affected: 'a'
  }
];

var svg = Madeline.draw(individuals, ['name', 'DOB']);
console.log(svg);
