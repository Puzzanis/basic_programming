INSERT INTO genres
(genre_name)
VALUES
('Rap'), 
('Rock'),
('Jazz'),
('Punk');


INSERT INTO artists
(artist_name)
VALUES
('Frank Sinatra'), --jazz
('Кино'),          --rock
('Король и шут'),  --punk
('Snoop Dogg');    --rap

INSERT INTO artist_genres
(artist_id, genre_id)
VALUES
(1, 3),
(2, 2),
(3, 4),
(4, 1);

INSERT INTO albums 
(album_title, release_year)
VALUES
('My Way', 2013),
('Звезда по имени Солнце', 1989),
('Как в старой сказке', 2014),
('Doggystyle', 1993);

INSERT INTO artist_albums
(artist_id, album_id)
values
(1, 1),
(2, 2),
(3, 3),
(4, 4);

INSERT INTO tracks 
(track_title, duration, album_id)
VALUES
('The World We Knew (Over And Over)', 167, 1),
('Somethin'' Stupid', 159, 1),
('All My Tomorrows', 194, 1),
('Печаль', 381, 2),
('Звезда по имени солнце', 226, 2),
('Пачка сигарет', 263, 2),
('Проклятый старый дом', 257, 3),
('Воспоминания о былой любви', 294, 3),
('Похороны панка', 139, 3),
('Bathtub', 176, 4),
('G Funk Intro', 144, 4),
('Gin and Juice', 300, 4);

INSERT INTO compilations 
(compilation_title, release_year)
VALUES
('Grand Collection', 2001),   				--кино
('Frank Sinatra''s Greatest Hits', 1967), 	--Frank Sinatra
('Лучшее', 2013),							--Король и шут			
('Snoop Dogg Best', 2014);

INSERT INTO compilation_tracks  
(compilation_id, track_id)
VALUES
(1, 5),   		
(1, 6),
(1, 7), 
(2, 1), 
(2, 2), 
(2, 3), 
(3, 7), 
(3, 8), 
(3, 9), 
(4, 10), 
(4, 11), 
(4, 12);