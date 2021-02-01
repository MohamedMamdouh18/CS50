SELECT movies.title FROM movies
join stars on stars.movie_id = movies.id
join people on people.id = stars.person_id
where name ="Helena Bonham Carter"
INTERSECT
SELECT movies.title FROM movies
join stars on stars.movie_id = movies.id
join people on people.id = stars.person_id
where name = "Johnny Depp"  ;
