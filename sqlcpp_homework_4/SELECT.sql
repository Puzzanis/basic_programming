-- Задание 2

--1. Название и продолжительность самого длительного трека.
select track_title, (interval '1 second' * duration) as duration from tracks
where  duration = (select MAX(duration) from tracks);

--2. Название треков, продолжительность которых не менее 3,5 минут.
select track_title, (interval '1 second' * duration) as duration from tracks
where  duration >= 210;

--3. Названия сборников, вышедших в период с 2013 по 2014 годы включительно.
select compilation_title from compilations
where  release_year between 2013 and 2014;

--4. Исполнители, чьё имя состоит из одного слова.
select artist_name from artists
where artist_name not like '% %';

--5. Название треков, которые содержат слова «мой» или «my».
select track_title from tracks
where 
(track_title like '%My%' or
 track_title like 'My%' or
 track_title like '%My' or
 track_title like '%my%' or
 track_title like 'my%' or
 track_title like '%my' or
 track_title like '%Мой%' or
 track_title like 'Мой%' or
 track_title like '%Мой' or
 track_title like '%мой%' or
 track_title like 'мой' or
 track_title like '%мой'
);

-- Задание 3

--1. Количество исполнителей в каждом жанре.
select genre_name, count(id) from genres
JOIN artist_genres ag on id = ag.genre_id 
group by genre_name;

--2. Количество треков, вошедших в альбомы 2013–2014 годов.
select a.album_title, count(a.id) from albums a
join tracks t on a.id = t.album_id and a.release_year between 2013 and 2014
group by a.album_title;

--3. Средняя продолжительность треков по каждому альбому.
select a.album_title, (interval '1 second' * AVG(t.duration)) as duration from albums a
join tracks t on a.id = t.album_id
group by a.album_title
order by duration;

--4. Все исполнители, которые не выпустили альбомы в 2014 году.
select artist_name from artists
join artist_albums aa on id = aa.artist_id
join albums a on a.id = aa.album_id and a.release_year < 2014
group by artist_name;

--5. Названия сборников, в которых присутствует конкретный исполнитель (выберите его сами).
select compilation_title from compilations
join compilation_tracks ct on id = ct.compilation_id
join tracks t on t.id = ct.track_id
join artist_albums aa on aa.album_id = t.album_id 
join artists a on a.id = aa.artist_id 
where a.artist_name = 'Frank Sinatra'
group by compilation_title;



