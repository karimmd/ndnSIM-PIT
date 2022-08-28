#!/bin/bash

# 10 consumer

./waf --run scratch/pure_sim10 && mv Pure_Consumer.txt throughput_pure_sim_10.txt && awk '{ total += $1; count++ } END { print count }' throughput_pure_sim_10.txt > Count_throughput_pure_sim_10.txt


# 20 consumer

./waf --run scratch/pure_sim20 && mv Pure_Consumer.txt throughput_pure_sim_20.txt && awk '{ total += $1; count++ } END { print count }' throughput_pure_sim_20.txt > Count_throughput_pure_sim_20.txt


# 30 consumer

./waf --run scratch/pure_sim30 && mv Pure_Consumer.txt throughput_pure_sim_30.txt && awk '{ total += $1; count++ } END { print count }' throughput_pure_sim_30.txt > Count_throughput_pure_sim_30.txt


# 40 consumer

./waf --run scratch/pure_sim40 && mv Pure_Consumer.txt throughput_pure_sim_40.txt && awk '{ total += $1; count++ } END { print count }' throughput_pure_sim_40.txt > Count_throughput_pure_sim_40.txt


# 50 consumer

./waf --run scratch/pure_sim50 && mv Pure_Consumer.txt throughput_pure_sim_50.txt && awk '{ total += $1; count++ } END { print count }' throughput_pure_sim_50.txt > Count_throughput_pure_sim_50.txt


# 60 consumer

./waf --run scratch/pure_sim60 && mv Pure_Consumer.txt throughput_pure_sim_60.txt && awk '{ total += $1; count++ } END { print count }' throughput_pure_sim_60.txt > Count_throughput_pure_sim_60.txt


# 70 consumer

./waf --run scratch/pure_sim70 && mv Pure_Consumer.txt throughput_pure_sim_70.txt && awk '{ total += $1; count++ } END { print count }' throughput_pure_sim_70.txt > Count_throughput_pure_sim_70.txt


# 80 consumer

./waf --run scratch/pure_sim80 && mv Pure_Consumer.txt throughput_pure_sim_80.txt && awk '{ total += $1; count++ } END { print count }' throughput_pure_sim_80.txt > Count_throughput_pure_sim_80.txt


# 90 consumer

./waf --run scratch/pure_sim90 && mv Pure_Consumer.txt throughput_pure_sim_90.txt && awk '{ total += $1; count++ } END { print count }' throughput_pure_sim_90.txt > Count_throughput_pure_sim_90.txt


# 100 consumer

./waf --run scratch/pure_sim100 && mv Pure_Consumer.txt throughput_pure_sim_100.txt && awk '{ total += $1; count++ } END { print count }' throughput_pure_sim_100.txt > Count_throughput_pure_sim_100.txt


# 200 consumer

#./waf --run scratch/pure_sim200 && mv Pure_Consumer.txt throughput_pure_sim_200.txt && awk '{ total += $1; count++ } END { print count }' throughput_pure_sim_200.txt > Count_throughput_pure_sim_200.txt


# 300 consumer

#./waf --run scratch/pure_sim300 && mv Pure_Consumer.txt throughput_pure_sim_300.txt && awk '{ total += $1; count++ } END { print count }' throughput_pure_sim_300.txt > Count_throughput_pure_sim_300.txt


# 400 consumer

#./waf --run scratch/pure_sim400 && mv Pure_Consumer.txt throughput_pure_sim_400.txt && awk '{ total += $1; count++ } END { print count }' throughput_pure_sim_400.txt > Count_throughput_pure_sim_400.txt


# 500 consumer

#./waf --run scratch/pure_sim500 && mv Pure_Consumer.txt throughput_pure_sim_500.txt && awk '{ total += $1; count++ } END { print count }' throughput_pure_sim_500.txt > Count_throughput_pure_sim_500.txt


awk '{print $0}' Count_throughput_pure_sim*.txt

mv *.txt /home/userx/GIT/ndnSIM-PIT/ns-3/plotting/result/

read -p "Press Any Key to Exit " -n1 -s
