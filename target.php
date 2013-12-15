<?php 
include 'html_dom.php';
if($_GET['type']=='ui_build')
{
for ($i=0;$i<count($_POST);$i++)
{
	
}
foreach($_POST as $k=>$value) { 
         $input.= "<DOC>\n"."<DOCNO>\n". htmlspecialchars($k)."\n</DOCNO>\n"."<TEXT>\n". file_get_html(htmlspecialchars($value))->plaintext."\n</TEXT>"."\n</DOC>\n";
    }
//Get ID
$filename = "/var/www/indri/id";
$handle = fopen($filename, "r");
$contents = fread($handle, filesize($filename));
echo "Your index id is ".$contents;
//Write input file
$my_file='./input/tmp';
$handle = fopen($my_file, 'w') or die('Cannot open file:  '.$my_file);
fwrite($handle, $input);
//Execute build
$old_path = getcwd();
chdir('/var/www/indri/');
$output = shell_exec('./index.sh');
chdir($old_path);
}
if($_GET['type']=='ui_query')
{
	$id=$_POST['id'];
	$op=$_POST['op'];
	if($op=='stats')
	{
		$output=shell_exec('./indri/dumpindex ./index/id_'.$id.' stats');
		echo "<pre>$output</pre>";
	}
}
?>

