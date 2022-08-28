# Gnuplot simple graph template

#reset

set terminal wxt size 800,600 font 'Liberation Sans,12'

#set term postscript eps color enhanced solid
#set encoding iso_8859_1
#set out 'caching.eps'


set autoscale

# Datafile options
#set datafile missing NaN
set datafile separator ','

#set key opaque right top horizontal
set key opaque right top vertical

# Grid style - grey thin dashed line
set style line 12 lc rgb '#808080' linewidth 1 dashtype 3
set grid back linestyle 12 

# We will use this for Bar Graph
set style data histograms
set style fill solid 1.00 border -1


# Range of plot
# '*' means automatic value based on data
#set yrange [8:40]
#set xrange [10:500]

set xtics (10,100,200,300,400,500)
#set ytics (300,4000,8000,12000,16000,20000)

set xlabel "No. of Consumers" offset 0,0.5

set ylabel "Flow Installation Time (ms)" offset 2,0

# line Plot Statement
plot "flow-norm.dat" using 1:2 title "100 contents per consumer" ls 7 lw 2 smooth cspline, '' using 1:3 title "200 contents per consumer" ls 8 lw 2 smooth cspline, '' using 1:4 title "300 contents per consumer" ls 6 lw 2 smooth cspline

# histograms Plot Statement

#plot "flow.dat"  using 2:xtic(1) title "100 contents per consumer" ls 7, '' using 3 title "200 contents per consumer" ls 2, '' using 4 title "300 contents per consumer" ls 6


pause -1
