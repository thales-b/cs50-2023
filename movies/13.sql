SELECT DISTINCT p.name
FROM people p
JOIN stars s1 ON p.id = s1.person_id
JOIN stars s2 ON s1.movie_id = s2.movie_id
JOIN people kb ON s2.person_id = kb.id
WHERE kb.name = 'Kevin Bacon'
  AND kb.birth = 1958
  AND p.name != 'Kevin Bacon';