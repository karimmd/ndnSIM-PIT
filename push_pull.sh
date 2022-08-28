#! /bin/bash
dt=$(date '+%d/%m/%Y %H:%M:%S');
echo "$dt"
echo $HOSTNAME

echo -e "Push and Pull to Github
1: Push to Master 
0: Pull from Master" 


read input


# Push to Master 
if [[ $input = "1" ]]; then


echo -e "\033[0;32mPushing updates to GitHub...\033[0m"

# Add changes to git.
git add .

# Commit changes.
msg="Updated on `date`"
if [ $# -eq 1 ]
  then msg="$1"
fi
git commit -m "$msg"

# Push source and build repos.
git push origin master

# Come Back up to the Project Root
cd .. 



# Pull from Master 
elif [[ $input = "0" ]]; then


echo -e "\033[0;32mPulling latest updates from GitHub...\033[0m"

# Push source and build repos.
git pull origin master

# Come Back up to the Project Root
cd .. 

else
read -p "You Press Wrong Keyword. GoodBye!!!!! " -n1 -s 
fi
read -p "Press Any Key to Exit " -n1 -s
