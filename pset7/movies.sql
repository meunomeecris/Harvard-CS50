-- 1 
SELECT title
FROM movies
WHERE year = 2008;

-- 2 
SELECT birth AS [Birth Year Emma Stone]
FROM people
WHERE name = 'Emma Stone';

-- 3 
SELECT title
FROM movies
WHERE year >= 2018
ORDER BY title ASC;

-- 4 
SELECT COUNT(rating)
FROM ratings
WHERE rating = 10.0;

-- 5 
SELECT title, year
FROM movies
WHERE title
LIKE 'Harry Potter%' 
ORDER BY year ASC;

-- 6 
SELECT AVG(rating)
FROM ratings
WHERE movie_id IN (
SELECT id FROM movies WHERE year = 2012);

-- 7 
SELECT title, rating
FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE year = 2010
ORDER BY rating DESC, title ASC;

-- 8 
SELECT name
FROM people
WHERE id IN (
    SELECT person_id
    FROM stars
    WHERE (
        SELECT id
        FROM movies
        WHERE title = 'Toy Story' ) = movie_id
        )
    ORDER BY birth ASC;

-- 9 
SELECT DISTINCT name FROM people WHERE id IN (
    SELECT person_id FROM stars WHERE movie_id IN (
        SELECT id FROM movies WHERE year = 2004))
    ORDER BY birth ASC;

-- 10 
SELECT DISTINCT name
FROM people WHERE id IN (
    SELECT person_id FROM directors WHERE movie_id IN (
        SELECT movie_id FROM ratings WHERE rating >= 9.0));

-- 11
SELECT title FROM movies
JOIN ratings ON movies.id = ratings.movie_id
JOIN stars ON ratings.movie_id = stars.movie_id
JOIN people ON stars.person_id = people.id WHERE name = 'Chadwick Boseman'
ORDER BY ratings.rating DESC
LIMIT 5;

-- 12 
SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id WHERE name = 'Bradley Cooper' OR name = 'Jennifer Lawrence'
GROUP BY title
HAVING COUNT(distinct people.name) = 2;


-- 13 
SELECT name FROM people WHERE id IN (
    SELECT person_id FROM stars WHERE movie_id IN (
        SELECT movie_id FROM stars WHERE person_id = (
            SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958
    )))
AND NOT name = 'Kevin Bacon';
