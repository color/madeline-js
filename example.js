Madeline = require('./madeline.js');

var columns = ['Individualid', 'Familyid', 'Gender', 'Mother', 'Father', 'DZTwin', 'MZTwin', 'DOB', 'Affected'];
var data = ['m100', 'test', 'f', '.', '.', '.', '.', '.', 'a',
            'm101', 'test', 'm', '.', '.', '.', '.', '.', 'b',
            'm102', 'test', 'f', '.', '.', '.', '.', '.', 'c',
            'm103', 'test', '', 'm100', 'm101', '.', 'test', '.', 'a',
            'm104', 'test', '', 'm102', 'm101', '.', '.', '.', 'b',
            'm105', 'test', '', 'm100', 'm101', '.', 'test', '.', 'c'];

var svg = Madeline.draw(columns, data);
console.log(svg);

