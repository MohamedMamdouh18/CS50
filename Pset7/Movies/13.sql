SELECT distinct(people.name)  FROM people
join stars on stars.person_id = people.id
join movies on stars.movie_id = movies.id
where title in
(SELECT movies.title FROM movies
join stars on stars.movie_id = movies.id
join people on people.id = stars.person_id
where name ="Kevin Bacon" and birth = 1958) 
and not name = "Kevin Bacon";

