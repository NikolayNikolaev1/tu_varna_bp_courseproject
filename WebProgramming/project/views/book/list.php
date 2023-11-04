<?php
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/book.service.php");
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/author.service.php");
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/publisher.service.php");
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/genre.service.php");

$book_service = new BookService($pdo);
$author_service = new AuthorService($pdo);
$publisher_service = new PublisherService($pdo);
$genre_service = new GenreService($pdo);

$all_books = $book_service->all();
$all_authors = $author_service->all();
$all_publishers = $publisher_service->all();
$all_genres = $genre_service->all();

$table_header = "
    <th>ID</th>
    <th>Title</th>
    <th>Author Name</th>
    <th>Release Year</th>
    <th>Publisher</th>
    <th>Genre</th>
    <th>Loan Count</th>
    <th>Is Available</th>
    <th>Actions</th>";
?>
<META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=utf-8">
<!DOCTYPE html>
<html>

<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <?php include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/utils/layout-constants.php");
    echo $bootstrap_scripts; ?>
    <title>Book list</title>
</head>

<body>

    <table class="table">
        <thead>

            <tr>
                <?php echo $table_header ?>

                <?php foreach ($all_books as $current_el): ?>
                <tr>
                    <?php $curr_id = 0;
                    $counter = 0; ?>
            </thead>

            <?php foreach ($current_el as $key => $value): ?>
                <?php if ($key == "id") {
                    $curr_id = $value;
                }

                ?>

                <form method="post">
                    <td>
                        <?php if ($key == "author_id"): ?>
                            <select class=form-control name=author id=author>
                                <?php foreach ($all_authors as $curr_author): ?>
                                    <option value=<?php echo $curr_author->id ?>                 
                                    <?php echo $curr_author->id == $current_el->author_id ? "selected" : "" ?>><?php echo $curr_author->first_name ?></option>
                                <?php endforeach; ?>
                            </select>
                        <?php elseif ($key == "publisher_id"): ?>
                            <select class=form-control name=publisher id=publisher>
                                <?php foreach ($all_publishers as $curr_publisher): ?>
                                    <option value=<?php echo $curr_publisher->id ?>                 
                                    <?php echo $curr_publisher->id == $current_el->publisher_id ? "selected" : "" ?>><?php echo $curr_publisher->name ?></option>
                                <?php endforeach; ?>
                            </select>
                        <?php elseif ($key == "genre_id"): ?>
                            <select class=form-control name=genre id=genre>
                                <?php foreach ($all_genres as $curr_genre): ?>
                                    <option value=<?php echo $curr_genre->id ?>                 
                                    <?php echo $curr_genre->id == $current_el->genre_id ? "selected" : "" ?>><?php echo $curr_genre->name ?></option>
                                <?php endforeach; ?>
                            </select>
                        <?php else: ?>
                            <input class="form-control" name=<?php echo $key ?> value=<?php echo $value ?> <?php echo $key == "id" || $key == "loan_count" || $key == "is_available" ? "disabled" : "" ?> />
                        <?php endif; ?>

                    </td>

                <?php endforeach; ?>

                <td>
                    <div class="form-group">
                        <input type="hidden" name="id" value=<?php echo $curr_id ?>>
                        <input class="btn btn-warning" type="submit" name="edit" value="Edit">
                    </div>
            </form>
            <form method="post">
                <input type="hidden" name="id" value=<?php echo $curr_id ?>>
                <input class="btn btn-danger" type="submit" name="delete" value="Delete">
            </form>
            </td>
            </tr>
        <?php endforeach; ?>
        </tr>
    </table>
</body>

    <form method="post" action="/WebProjectTU/views/book/filter.php">
        
        <div class="form-group">
            <label for="title">Search by title:</label>
            <input class="form-control" id="title" name="title" type="text">
        </div>

        <input class="btn btn-primary" type="submit" name="filter-title" value="Filter by Title">

        <div class="form-group">
            <label for="author_name">Search by author first name:</label>
            <input class="form-control" id="author_name" name="author_name" type="text">
        </div>

        <input class="btn btn-primary" type="submit" name="filter-author" value="Filter by Author">

        
        <div class="form-group">
            <label for="genre_name">Search by genre name:</label>
            <input class="form-control" id="genre_name" name="genre_name" type="text">
        </div>

        <input class="btn btn-primary" type="submit" name="filter-genre" value="Filter by Author">
        
    </form>

</html>

<?php
if (isset($_POST["delete"])) {
    $current_book_id = $_POST["id"];
    $book_service->delete($current_book_id);

} else if (isset($_POST["edit"])) {
    $curr_id = $_POST["id"];
    $title = $_POST["title"];
    $author_id = $_POST["author"];
    $release_year = $_POST["release_year"];
    $publisher_id = $_POST["publisher"];
    $genre_id = $_POST["genre"];
    $genre_id = $_POST["genre"];


    $emp = $book_service->edit($curr_id, $title, $author_id, $release_year, $publisher_id, $genre_id);
}
?>