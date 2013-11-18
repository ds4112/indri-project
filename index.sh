#!/bin/bash
typeset -i var_id=$(cat id)
path="/home/dan/Projects/input"
class="trectext"
index="/home/dan/Projects/id_$var_id"
cmd="./IndriBuildIndex -corpus.path=$path -corpus.class=$class -index=$index"
eval $cmd
num=1
res=$(($num+$var_id))
echo "$res" > 'id'
