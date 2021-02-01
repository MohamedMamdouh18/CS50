SELECT movies.title , ratings.rating FROM movies
join ratings on movies.id = ratings.movie_id 
where year = 2010
order by ratings.rating desc , movies.title;
