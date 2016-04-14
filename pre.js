module.exports.draw = function(individuals, labels) {
  var madeline = {};
  var columns = {};
  var data = [];
  var svg;

  if (typeof labels === 'undefined') {
    labels = [];
  }

  (function(Module) {
