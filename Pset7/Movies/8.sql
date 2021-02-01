SELECT people.name  FROM people
join stars on stars.person_id = people.id 
join movies on stars.movie_id = movies.id
where title = "Toy Story";
