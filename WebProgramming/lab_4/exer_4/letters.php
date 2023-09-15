<html>
    <head>
 <title>My first program!
</title>
 </head>
<body>
    

 <?php
    include 'data.php';

    $selected_person = $people[array_rand($people)];
    $selected_event = $events[array_rand($events)];
    
    echo "Dear, $selected_person</br>We have the pleassure to invite you to $selected_event.</br>";

    switch ($selected_event) {
        case "Open Event":
            echo "Be 10 minutes before the opening!";
            break;
        case "School Prom":
            echo "Do not forget to bring a present with you :)";
            break;
        case "Open Doors":
            echo "Please, call us to confirm your comming";
            break;
    }

    echo "</br>With gratitude, Dean Ivanov!"

 
 ?>
</body>
</html>