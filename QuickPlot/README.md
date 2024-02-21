# QuickPlot folder
Here you can find the code to make the graph plots from .csv files.

Note that the macro needs as argument `(Double_t threshold_lower_limit,Double_t threshold_upper_limit, TString path_to_csv)`.
You can run the macro using the command: `root -l -b 'quickplot.cpp(lower_threshold,upper_threshold,"csv_path_name")'`.
After that you will find in the Result folder the plots
