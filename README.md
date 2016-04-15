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
    Affected: 'a'
  }, {
    IndividualId: 'm101',
    Familyid: 'test',
    Gender: 'm',
    Affected: 'b'
  }, {
    IndividualId: 'm102',
    Familyid: 'test',
    Gender: 'f',
    Affected: 'c'
  }, {
    IndividualId: 'm103',
    Familyid: 'test',
    Mother: 'm100',
    Father: 'm101',
    MZTwin: 'test',
    Affected: 'a'
  }, {
    IndividualId: 'm104',
    Familyid: 'test',
    Gender: 'f',
    Mother: 'm102',
    Father: 'm101',
    Affected: 'b'
  }, {
    IndividualId: 'm105',
    Familyid: 'test',
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
    Mother: 'm104',
    Father: 'm106',
    DZTwin: 'rest',
    Affected: 'a'
  }, {
    IndividualId: 'm108',
    Familyid: 'test',
    Mother: 'm104',
    Father: 'm106',
    DZTwin: 'rest',
    Affected: 'a'
  }
];

var svg = Madeline.draw(individuals,  ['IndividualId', 'DOB']);
```


Copyright
=========

Madeline 2.0 PDE is written by Ed Trager, Ritu Khanna, and Adrian Marrs, with
additional contributions by a few other people.

This JavaScript port is done by Jonathan Vis and Martijn Vermaat.
