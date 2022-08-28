#!/bin/bash

# 10 consumer

./waf --run scratch/sdn_sim10 && mv FlowInstallion.txt FlowInstallion_sdn_sim_10.txt && awk '{ total += $1; count++ } END { print total/(100*10) }' FlowInstallion_sdn_sim_10.txt > Count_FlowInstallion_sdn_sim_10.txt


# 20 consumer

./waf --run scratch/sdn_sim20 && mv FlowInstallion.txt FlowInstallion_sdn_sim_20.txt && awk '{ total += $1; count++ } END { print total/(100*20) }' FlowInstallion_sdn_sim_20.txt > Count_FlowInstallion_sdn_sim_20.txt


# 30 consumer

./waf --run scratch/sdn_sim30 && mv FlowInstallion.txt FlowInstallion_sdn_sim_30.txt && awk '{ total += $1; count++ } END { print total/(100*30) }' FlowInstallion_sdn_sim_30.txt > Count_FlowInstallion_sdn_sim_30.txt


# 40 consumer

./waf --run scratch/sdn_sim40 && mv FlowInstallion.txt FlowInstallion_sdn_sim_40.txt && awk '{ total += $1; count++ } END { print total/(100*40) }' FlowInstallion_sdn_sim_40.txt > Count_FlowInstallion_sdn_sim_40.txt


# 50 consumer

./waf --run scratch/sdn_sim50 && mv FlowInstallion.txt FlowInstallion_sdn_sim_50.txt && awk '{ total += $1; count++ } END { print total/(100*50) }' FlowInstallion_sdn_sim_50.txt > Count_FlowInstallion_sdn_sim_50.txt


# 60 consumer

./waf --run scratch/sdn_sim60 && mv FlowInstallion.txt FlowInstallion_sdn_sim_60.txt && awk '{ total += $1; count++ } END { print total/(100*60) }' FlowInstallion_sdn_sim_60.txt > Count_FlowInstallion_sdn_sim_60.txt


# 70 consumer

./waf --run scratch/sdn_sim70 && mv FlowInstallion.txt FlowInstallion_sdn_sim_70.txt && awk '{ total += $1; count++ } END { print total/(100*70) }' FlowInstallion_sdn_sim_70.txt > Count_FlowInstallion_sdn_sim_70.txt


# 80 consumer

./waf --run scratch/sdn_sim80 && mv FlowInstallion.txt FlowInstallion_sdn_sim_80.txt && awk '{ total += $1; count++ } END { print total/(100*80) }' FlowInstallion_sdn_sim_80.txt > Count_FlowInstallion_sdn_sim_80.txt


# 90 consumer

./waf --run scratch/sdn_sim90 && mv FlowInstallion.txt FlowInstallion_sdn_sim_90.txt && awk '{ total += $1; count++ } END { print total/(100*90) }' FlowInstallion_sdn_sim_90.txt > Count_FlowInstallion_sdn_sim_90.txt


# 100 consumer

#./waf --run scratch/sdn_sim100 && mv FlowInstallion.txt FlowInstallion_sdn_sim_100.txt && awk '{ total += $1; count++ } END { print total/(100*100) }' FlowInstallion_sdn_sim_100.txt > Count_FlowInstallion_sdn_sim_100.txt


# 200 consumer

#./waf --run scratch/sdn_sim200 && mv FlowInstallion.txt FlowInstallion_sdn_sim_200.txt && awk '{ total += $1; count++ } END { print total/(100*200) }' FlowInstallion_sdn_sim_200.txt > Count_FlowInstallion_sdn_sim_200.txt


# 300 consumer

#./waf --run scratch/sdn_sim300 && mv FlowInstallion.txt FlowInstallion_sdn_sim_300.txt && awk '{ total += $1; count++ } END { print total/(100*300) }' FlowInstallion_sdn_sim_300.txt > Count_FlowInstallion_sdn_sim_300.txt


# 400 consumer

#./waf --run scratch/sdn_sim400 && mv FlowInstallion.txt FlowInstallion_sdn_sim_400.txt && awk '{ total += $1; count++ } END { print total/(100*400) }' FlowInstallion_sdn_sim_400.txt > Count_FlowInstallion_sdn_sim_400.txt


# 500 consumer

#./waf --run scratch/sdn_sim500 && mv FlowInstallion.txt FlowInstallion_sdn_sim_500.txt && awk '{ total += $1; count++ } END { print total/(100*500) }' FlowInstallion_sdn_sim_500.txt > Count_FlowInstallion_sdn_sim_500.txt


awk '{print $0}' Count_FlowInstallion_sdn_sim*.txt

rm Count_FlowInstallion_sdn*.txt && rm FlowInstallion_sdn_sim*.txt 

read -p "Press Any Key to Exit " -n1 -s