    <?php
        class Person {
            private $first_name;
            private $last_name;

            function __construct($first_name, $last_name) {
                $this->first_name = $first_name;
                $this->last_name = $last_name;
            }

            function show_person() {
                return "Hello!</br>My name is, $this->first_name $this->last_name";
            }
        }

        class Programmer extends Person {
            private $langs;

            function set_langs($langs) {
                $this->langs = $langs;
            }

            function show_person() {
                return parent::show_person() . "</br>I know also " . end($this->langs) . ".";
            }
        }

        $programmer = new Programmer("Ivan", "Ivanov");
        $programmer->set_langs(["Lisp", "PHP"]);
        echo $programmer->show_person();
    ?>