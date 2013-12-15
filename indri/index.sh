#!/bin/bash
typeset -i var_id=$(cat id)
path="/var/www/input"
class="trectext"
index="/var/www/index/id_$var_id"
cmd="/var/www/indri/IndriBuildIndex -corpus.path=$path -corpus.class=$class -index=$index"
eval $cmd
num=1
res=$(($num+$var_id))
echo "$res" > 'id'
