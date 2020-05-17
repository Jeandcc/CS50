SELECT title
FROM movies
JOIN ratings
ON movies.id = ratings.movie_id
WHERE id
IN (
  SELECT movie_id
  FROM stars
  WHERE person_id = 
  (
    SELECT id 
    from PEOPLE
    WHERE name = "Chadwick Boseman"
  )
)
ORDER BY rating DESC