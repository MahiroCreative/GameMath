$pdf_mode = 3;

# Put all build artifacts under out/ by default.
$out_dir = 'out';
$aux_dir = 'out';

$latex = 'uplatex -synctex=1 -halt-on-error -interaction=nonstopmode %O %S';
$dvipdf = 'dvipdfmx %O -o %D %S';