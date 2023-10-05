
<?php
    class Donation {
        static $totalDonated = 0;
        static $numberOfDonors = 0;
        private $name;
        private $amount;

        function __construct($name, $amount) {
            $this->name = $name;
            $this->amount = $amount;

            self::$totalDonated += $amount;
            self::$numberOfDonors++;
        }

        function info() {
            return "$this->name donated $this->amount (" . round(($this->amount * 100) / self::$totalDonated, 2) . ")";
        }
    }
    
    $donors = [
        new Donation("Nichola", 85),
        new Donation("Mitko", 50),
        new Donation("Emily", 90),
        new Donation("Iliana", 65),
    ];

    foreach ($donors as $current_donor) {
        echo $current_donor->info() . "<br/>";
    }
    
    echo "Total Donations = " . Donation::$totalDonated;
    echo "<br /> Number of Donors = " . Donation::$numberOfDonors;
 ?>