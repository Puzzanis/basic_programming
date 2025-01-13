CREATE TABLE if not exists genres (
    id SERIAL PRIMARY KEY,
    genre_name VARCHAR(255) NOT NULL UNIQUE
);

CREATE table if not exists artists (
    id SERIAL PRIMARY KEY,
    artist_name VARCHAR(255) NOT NULL
);

CREATE table if not exists albums (
    id SERIAL PRIMARY KEY,
    album_title VARCHAR(255) NOT NULL,
    release_year INTEGER
);

CREATE table if not exists tracks (
    id SERIAL PRIMARY KEY,
    track_title VARCHAR(255) NOT NULL,
    duration INTEGER,
    album_id INTEGER REFERENCES albums(id)
);

CREATE table if not exists compilations (
    id SERIAL PRIMARY KEY,
    compilation_title VARCHAR(255) NOT NULL,
    release_year INTEGER
);

CREATE table if not exists artist_genres (
    artist_genre_id SERIAL PRIMARY KEY,
    artist_id INTEGER REFERENCES artists(id),
    genre_id INTEGER REFERENCES genres(id)
);

CREATE table if not exists artist_albums (
    artist_album_id SERIAL PRIMARY KEY,
    artist_id INTEGER REFERENCES artists(id),
    album_id INTEGER REFERENCES albums(id)
);

CREATE table if not exists compilation_tracks (
    compilation_track_id SERIAL PRIMARY KEY,
    compilation_id INTEGER REFERENCES compilations(id),
    track_id INTEGER REFERENCES tracks(id)
);