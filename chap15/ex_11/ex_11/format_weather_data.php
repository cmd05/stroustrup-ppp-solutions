<pre>
<?php

// ----- NOTE: empty line 5 of csv before parsing --------

$file = "Weather Data/tokyo.csv";
$csv = array_map('str_getcsv', file($file));

// Remove meta information until we get numeric data
foreach ($csv as $key => $item) {
    if(!is_numeric($item[1])) unset($csv[$key]);
    else break;
}

// Reorder indexes
$csv = array_values($csv);
// Start from jan 1
$csv = array_reverse($csv);

$months = ["01" => "jan",
           "02" => "feb",
           "03" => "mar",
           "04" => "apr",
           "05" => "may",
           "06" => "jun",
           "07" => "jul",
           "08" => "aug",
           "09" => "sep",
           "10" => "oct",
           "11" => "nov",
           "12" => "dec"];
           
$entries = [];

// Save useful information
foreach($csv as $item) {
    $entry = [];
    $entry["day"] = substr($item[0], 0, 2);
    $entry["month"] = substr($item[0], 3, 2);
    $entry["temp"] = $item[1];
    $entries[] = $entry;
}

// Output in usable format
$prev_day = '';
foreach($months as $mt => $mt_name) {
    echo "  month $mt_name { ";
    foreach($entries as $entry) {
        if($entry["month"] == $mt) {
            if($entry['day'] != $prev_day) {
                if($entry['day'] != '01') echo ") ";
                echo "( ";
            }
 
            echo $entry["temp"]." ";
        }
        $prev_day = $entry['day'];
    }   
    echo ") } <br>";
}