data = readmatrix('Sorted_Data.csv');
disp(data);

heights = data(:, 2);

histogram(heights, length(y), 'FaceColor', '#7E2F8E');

title('Frequency of building heights');
xlabel('Height (Feet)');
ylabel('Frequency');

grid on;