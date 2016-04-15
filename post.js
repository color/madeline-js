  })(madeline);

  individuals.forEach(function(individual) {
    Object.keys(individual).forEach(function(column) {
      columns[column] = true;
    });
  });
  columns = Object.keys(columns);

  data = individuals.map(function(individual) {
    return columns.map(function(column) {
      return individual[column] || '';
    });
  }).reduce(function(a, b) {
    return a.concat(b);
  });

  try {
    svg = madeline.draw(columns, data, labels);
  }
  catch (excp) {
    console.log('Exception:', excp);
  }

  if (!svg) {
    console.warn('Could not render pedigree with Madeline.');
    console.log('Original pedigree:', individuals);
    console.log('Extracted columns:', columns);
    console.log('Extracted data:', data);
  }

  return svg;
};
