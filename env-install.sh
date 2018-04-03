gazeboPlugin="export GAZEBO_PLUGIN_PATH=`pwd`/plugins:\$GAZEBO_PLUGIN_PATH"
gazeboModel="export GAZEBO_MODEL_PATH=`pwd`/models:\$GAZEBO_MODEL_PATH"
bashrc=$HOME/.bashrc

grep "$gazeboPlugin" $bashrc
pluginInscribed=$?
grep "$gazeboModel" $bashrc
modelInscrisbed=$?
export GAZEBO_PLUGIN_PATH=`pwd`/plugin:$GAZEBO_PLUGIN_PATH
export GAZEBO_MODEL_PATH=`pwd`/model:$GAZEBO_MODEL_PATH
if [ $pluginInscribed -eq 1 -o $modelInscrisbed -eq 1 ]
then
  echo $gazeboPlugin >> $bashrc
  echo $gazeboModel >> $bashrc
  echo "Environnement variable GAZEBO_MODEL_PATH and GAZEBO_PLUGIN_PATH set."
fi

echo "End of script"
return 0
