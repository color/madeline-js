var Madeline = require('./madeline.js');

var individuals = [
  {
    IndividualId: 'm100',
    Familyid: 'test',
    Gender: 'f',
    Mother: '.',
    Father: '.',
    DZTwin: '.',
    MZTwin: '.',
    DOB: '.',
    Affected: 'a'
  }, {
    IndividualId: 'm101',
    Familyid: 'test',
    Gender: 'm',
    Mother: '.',
    Father: '.',
    DZTwin: '.',
    MZTwin: '.',
    DOB: '.',
    Affected: 'b'
  }, {
    IndividualId: 'm102',
    Familyid: 'test',
    Gender: 'f',
    Mother: '.',
    Father: '.',
    DZTwin: '.',
    MZTwin: '.',
    DOB: '.',
    Affected: 'c'
  }, {
    IndividualId: 'm103',
    Familyid: 'test',
    Gender: '',
    Mother: 'm100',
    Father: 'm101',
    DZTwin: '.',
    MZTwin: 'test',
    DOB: '.',
    Affected: 'a'
  }, {
    IndividualId: 'm104',
    Familyid: 'test',
    Gender: 'f',
    Mother: 'm102',
    Father: 'm101',
    DZTwin: '.',
    MZTwin: '.',
    DOB: '.',
    Affected: 'b'
  }, {
    IndividualId: 'm105',
    Familyid: 'test',
    Gender: '',
    Mother: 'm100',
    Father: 'm101',
    DZTwin: '.',
    MZTwin: 'test',
    DOB: '.',
    Affected: 'c'
  }, {
    IndividualId: 'm106',
    Familyid: 'test',
    Gender: 'm',
    Mother: '.',
    Father: '.',
    DZTwin: '.',
    MZTwin: '.',
    DOB: '.',
    Affected: ''
  }, {
    IndividualId: 'm107',
    Familyid: 'test',
    Gender: '',
    Mother: 'm104',
    Father: 'm106',
    DZTwin: 'rest',
    MZTwin: '',
    DOB: '',
    Affected: 'a'
  }, {
    IndividualId: 'm108',
    Familyid: 'test',
    Gender: '',
    Mother: 'm104',
    Father: 'm106',
    DZTwin: 'rest',
    MZTwin: '',
    DOB: '12/12/12',
    Affected: 'a'
  }
];

var svg = Madeline.draw(individuals, ['individualid', 'DOB']);
console.log(svg);
