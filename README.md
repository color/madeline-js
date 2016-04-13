Madeline JS
===========

This is a proof-of-concept JavaScript port of
[Madeline 2.0 PDE](https://github.com/piratical/Madeline_2.0_PDE).

The port is an automatic translation using
[Emscripten](https://github.com/kripken/emscripten).

Building
--------

`source <path>/<to>/emsdk_env.sh`

`make`

Example usage:

```javascript
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
    DOB: '.',
    Affected: 'a'
  }
];

var svg = Madeline.draw(individuals);
```


Copyright
=========

Madeline 2.0 PDE is written by Ed Trager, Ritu Khanna, and Adrian Marrs, with
additional contributions by a few other people.

This JavaScript port is done by Jonathan Vis and Martijn Vermaat.
