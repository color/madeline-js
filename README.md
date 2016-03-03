Madeline JS
===========

This is a proof-of-concept JavaScript port of
[Madeline 2.0 PDE](https://github.com/piratical/Madeline_2.0_PDE).

The port is an automatic translation using
[Emscripten](https://github.com/kripken/emscripten).

Example usage:

```javascript
Madeline = require('madeline');

var columns = ['Individualid', 'Familyid', 'Gender', 'Mother', 'Father'];
var data = ['m100', 'cs_001', 'm', '.', '.',
            'm101', 'cs_001', 'f', '.', '.',
            'm102', 'cs_001', 'm', 'm101', 'm100',
            'm103', 'cs_001', 'f', 'm101', 'm100',
            'm104', 'cs_001', 'm', '.', '.',
            'm105', 'cs_001', 'f', 'm101', 'm100',
            'm106', 'cs_001', 'm', '.', '.',
            'm107', 'cs_001', 'm', 'm101', 'm100',
            'm109', 'cs_001', 'm', 'm103', 'm104',
            'm108', 'cs_001', 'm', 'm103', 'm104',
            'm110', 'cs_001', 'm', 'm114', 'm108',
            'm111', 'cs_001', 'm', 'm114', 'm108',
            'm114', 'cs_001', 'f', 'm105', 'm106',
            'm112', 'cs_001', 'm', 'm105', 'm106'];

var svg = Madeline.render(columns, data)
```


Copyright
=========

Madeline 2.0 PDE is written by Ed Trager, Ritu Khanna, and Adrian Marrs, with
additional contributions by a few other people.

This JavaScript port is done by Jonathan Vis and Martijn Vermaat.
