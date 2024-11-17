


CREATE TABLE roles (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_roles,
    name VARCHAR2(50) NOT NULL CONSTRAINT unique_roles_name UNIQUE
);

INSERT INTO roles (name) VALUES ('admin');
INSERT INTO roles (name) VALUES ('user');

CREATE TABLE users (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_users,
    email VARCHAR2(255) NOT NULL CONSTRAINT unique_users_email UNIQUE,
    password VARCHAR2(255) NOT NULL,
    role_id NUMBER CONSTRAINT fk_users_roles REFERENCES roles(id) NOT NULL DEFAULT 2,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    last_login TIMESTAMP,
    is_email_verified BOOLEAN DEFAULT FALSE
);


CREATE TABLE frequency (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_frequency,
    name VARCHAR2(50) NOT NULL CONSTRAINT unique_frequency_name UNIQUE
);

INSERT INTO frequency (name) VALUES ('once');
INSERT INTO frequency (name) VALUES ('daily');
INSERT INTO frequency (name) VALUES ('weekly');
INSERT INTO frequency (name) VALUES ('monthly');
INSERT INTO frequency (name) VALUES ('yearly');


-- INTERNATIONALISATION

CREATE TABLE nationality (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_nationality,
    name VARCHAR2(50) NOT NULL CONSTRAINT unique_nationality_name UNIQUE
);




-- CREATE TABLE translations (
--     id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_translations,
--     entity_name VARCHAR2(50) NOT NULL,    -- Nom de l'entité (par ex. 'options')
--     entity_id NUMBER NOT NULL,            -- ID de l'élément dans l'entité (lié à 'options.id')
--     lang_code VARCHAR2(2) NOT NULL,       -- Code de la langue (par ex. 'en', 'fr')
--     field_name VARCHAR2(50) NOT NULL,     -- Nom du champ traduit (par ex. 'name', 'description')
--     translation CLOB NOT NULL,            -- Contenu traduit
--     updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
--     CONSTRAINT unique_translation UNIQUE (entity_name, entity_id, lang_code, field_name)
-- );

-- -- table polymorphique
-- CREATE TABLE translations (
--     id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_translations,
--     entity_name VARCHAR2(50) NOT NULL,    -- Nom de l'entité (par ex. 'seasons', 'roles')
--     entity_id NUMBER NOT NULL,            -- ID de l'élément dans l'entité (lié à plusieurs tables)
--     lang_code VARCHAR2(2) NOT NULL,       -- Code de la langue (par ex. 'en', 'fr')
--     field_name VARCHAR2(50) NOT NULL,     -- Nom du champ traduit (par ex. 'name', 'description')
--     translation CLOB NOT NULL,            -- Contenu traduit
--     updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
--     CONSTRAINT unique_translation UNIQUE (entity_name, entity_id, lang_code, field_name)
-- );

CREATE TABLE translations (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
    entity JSONB NOT NULL,                -- Structure JSON : {"table": "seasons", "id": 1}
    lang_code VARCHAR2(2) NOT NULL,
    field_name VARCHAR2(50) NOT NULL,
    translation CLOB NOT NULL,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    CONSTRAINT unique_translation UNIQUE (entity, lang_code, field_name)
);



CREATE TABLE user_profiles (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_user_profiles,
    user_id NUMBER CONSTRAINT fk_user_profiles_users REFERENCES users(id) NOT NULL ON DELETE CASCADE,
    first_name VARCHAR2(50) NOT NULL,
    last_name VARCHAR2(50) NOT NULL,
    nationality_id NUMBER CONSTRAINT fk_user_profiles_nationality REFERENCES nationality(id) ON DELETE SET NULL,
    preferred_language_id NUMBER CONSTRAINT fk_user_profiles_preferred_language REFERENCES nationality(id) ON DELETE SET NULL,
    accepts_marketing BOOLEAN DEFAULT TRUE,
    first_stay_remembered BOOLEAN,
    first_stay_date DATE CHECK (first_stay_date >= '1960-01-01' OR first_stay_date IS NULL) CONSTRAINT chk_user_profiles_first_stay_date,
    stay_frequency NUMBER CONSTRAINT fk_user_profiles_frequency REFERENCES frequency(id) DEFAULT 1 ON DELETE SET NULL
);


CREATE TABLE newsletters (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_newsletters,
    email VARCHAR2(255) NOT NULL CONSTRAINT unique_newsletters_email UNIQUE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    status VARCHAR2(50) DEFAULT 'subscribed' CHECK (status IN ('subscribed', 'unsubscribed', 'bounced')) CONSTRAINT chk_newsletters_status
);

-- gerer le lien entre newsletter et user via une vue


-- reflechir à la structure pour le stockage des cookies et des photos

-- Table des saisons
CREATE TABLE seasons (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_seasons,
    name VARCHAR2(50) NOT NULL CONSTRAINT unique_seasons_name UNIQUE
);

-- Table des périodes liées aux saisons
CREATE TABLE season_periods (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
    season_id NUMBER NOT NULL CONSTRAINT fk_season_periods REFERENCES seasons(id) ON DELETE CASCADE,
    start_date DATE NOT NULL,
    end_date DATE NOT NULL,
    CONSTRAINT chk_period_dates CHECK (start_date < end_date),
    CONSTRAINT unique_season_period UNIQUE (season_id, start_date, end_date) 
);


-- Haute, basse, estivale. Date a changer
INSERT INTO seasons (name) VALUES ('High');
INSERT INTO seasons (name) VALUES ('Low');
INSERT INTO seasons (name) VALUES ('Summer');

-- mettre les bonnes dates
-- INSERT INTO season_periods (season_id, start_date, end_date) VALUES (1, '2021-06-01', '2021-08-31');
-- INSERT INTO season_periods (season_id, start_date, end_date) VALUES (1, '2021-06-01', '2021-08-31');
-- INSERT INTO season_periods (season_id, start_date, end_date) VALUES (2, '2021-09-01', '2021-12-31');
-- INSERT INTO season_periods (season_id, start_date, end_date) VALUES (3, '2021-01-01', '2021-05-31');

INSERT INTO translations (entity_name, entity_id, lang_code, field_name, translation)
VALUES 
    ('seasons', 1, 'en', 'name', 'High'),
    ('seasons', 1, 'fr', 'name', 'Haute'),
    ('seasons', 2, 'en', 'name', 'Low'),
    ('seasons', 2, 'fr', 'name', 'Basse'),
    ('seasons', 3, 'en', 'name', 'Summer'),
    ('seasons', 3, 'fr', 'name', 'Estivale');


CREATE TABLE room_types (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_room_types,
    name VARCHAR2(50) NOT NULL CONSTRAINT unique_room_types_name UNIQUE
);

CREATE TABLE hotel_options (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_options,
    name VARCHAR2(50) NOT NULL CONSTRAINT unique_options_name UNIQUE,
    additional_cost NUMBER(10, 2) DEFAULT 0
);

CREATE TABLE hotel_services (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_services,
    name VARCHAR2(50) NOT NULL CONSTRAINT unique_services_name UNIQUE,
    additional_cost NUMBER(10, 2) DEFAULT 0
);

CREATE TABLE hotel_services_schedule (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_services_schedule,
    service_id NUMBER CONSTRAINT fk_services_schedule_services REFERENCES hotel_services(id) NOT NULL ON DELETE CASCADE,
    schedule INTERVAL DAY TO SECOND NOT NULL -- Stocke une heure générique comme '10:00'
);

CREATE TABLE room_rates (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_room_rates,
    room_type_id NUMBER NOT NULL CONSTRAINT fk_room_rates_room_types REFERENCES room_types(id) ON DELETE CASCADE,
    season_period_id NUMBER NOT NULL CONSTRAINT fk_room_rates_season_periods REFERENCES season_periods(id) ON DELETE CASCADE,
    price_per_night NUMBER(10, 2) NOT NULL CHECK (price_per_night > 0),
    CONSTRAINT unique_room_rate UNIQUE (room_type_id, season_period_id) -- Empêche les doublons
);

CREATE TABLE status (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_status,
    name VARCHAR2(50) NOT NULL CONSTRAINT unique_status_name UNIQUE
);

CREATE TABLE reservation_quotes ( 
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_reservation_quotes,
    user_id NUMBER CONSTRAINT fk_reservation_quotes_users REFERENCES users(id) NOT NULL ON DELETE CASCADE,
    from DATE NOT NULL,
    to DATE NOT NULL,
    adults NUMBER NOT NULL DEFAULT 1,
    children NUMBER NOT NULL DEFAULT 0,
    promoCode VARCHAR2(50),
    total_price NUMBER(10, 2) NOT NULL CHECK (total_price > 0),
    pdfQuoted BLOB, -- stockage du PDF de la quote

    status_id NUMBER CONSTRAINT fk_reservation_quotes_status REFERENCES status(id) NOT NULL,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, -- Permet de suivre le changement de statut
    CONSTRAINT chk_reservation_dates CHECK (from < to)
);



CREATE TABLE room_quotes (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_room_quotes,
    reservation_quote_id NUMBER CONSTRAINT fk_room_quotes_reservation_quotes REFERENCES reservation_quotes(id) NOT NULL ON DELETE CASCADE,
    room_type_id NUMBER CONSTRAINT fk_room_quotes_room_types REFERENCES room_types(id) NOT NULL ON DELETE CASCADE,
    price_per_night_for_this_quotes NUMBER(10, 2) NOT NULL CHECK (price_per_night_for_this_quotes > 0)
);

CREATE TABLE room_options_quote (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_room_options_quote,
    room_quote_id NUMBER CONSTRAINT fk_room_options_quote_room_quotes REFERENCES room_quotes(id) NOT NULL ON DELETE CASCADE,
    option_id NUMBER CONSTRAINT fk_room_options_quote_options REFERENCES hotel_options(id) NOT NULL ON DELETE SET NULL
);

CREATE TABLE saison_quotes (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_saison_quotes,
    reservation_quote_id NUMBER CONSTRAINT fk_saison_quotes_reservation_quotes REFERENCES reservation_quotes(id) NOT NULL ON DELETE CASCADE,
    season_period_id NUMBER CONSTRAINT fk_saison_quotes_season_periods REFERENCES season_periods(id) NOT NULL ON DELETE SET NULL
);

CREATE TABLE service_quotes (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_service_quotes,
    reservation_quote_id NUMBER CONSTRAINT fk_service_quotes_reservation_quotes REFERENCES reservation_quotes(id) NOT NULL ON DELETE CASCADE,
    service_id NUMBER CONSTRAINT fk_service_quotes_services REFERENCES hotel_services(id) NOT NULL ON DELETE SET NULL,
    schedule_id NUMBER CONSTRAINT fk_service_quotes_schedule REFERENCES hotel_services_schedule(id) ON DELETE SET NULL
);



CREATE TABLE client_types (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_client_types,
    name VARCHAR2(50) NOT NULL CONSTRAINT unique_client_types_name UNIQUE
);



-- reste a regler le probleme de country, nationality, preferred_language
CREATE TABLE clients (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_clients,
    client_type_id NUMBER CONSTRAINT fk_clients_client_types REFERENCES client_types(id) NOT NULL,
    reservation_quote_id NUMBER CONSTRAINT fk_clients_reservation_quotes REFERENCES reservation_quotes(id) ON DELETE CASCADE,
    email VARCHAR2(255) NOT NULL,
    address VARCHAR2(255),
    postal_code VARCHAR2(10),
    city VARCHAR2(100),
    country VARCHAR2(100),
    phone_number VARCHAR2(20),
    cgv_accepted BOOLEAN DEFAULT TRUE,
    whatsapp BOOLEAN DEFAULT FALSE,
    questions VARCHAR2(500),
    remarques VARCHAR2(500),
    first_time BOOLEAN DEFAULT TRUE,
    incoming_mode VARCHAR2(255),
    reason VARCHAR2(255)
);

CREATE TABLE companies (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_companies,
    client_id NUMBER CONSTRAINT fk_companies_clients REFERENCES clients(id) NOT NULL ON DELETE CASCADE,
    company_name VARCHAR2(255) NOT NULL,
    company_vat VARCHAR2(50),
    company_siret VARCHAR2(50),
    billing_address VARCHAR2(255),
    billing_postal_code VARCHAR2(10),
    billing_city VARCHAR2(100),
    billing_country VARCHAR2(100),
    responsible_name VARCHAR2(100),
    responsible_email VARCHAR2(255),
    responsible_phone VARCHAR2(20),
    responsible_function VARCHAR2(100),
    intra_eu_invoice BOOLEAN DEFAULT FALSE
);



CREATE TABLE individuals (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_individuals,
    client_id NUMBER CONSTRAINT fk_individuals_clients REFERENCES clients(id) NOT NULL ON DELETE CASCADE,
    first_name VARCHAR2(50) NOT NULL,
    last_name VARCHAR2(50) NOT NULL,
    -- nationality VARCHAR2(100) -- table des nationalités
    nationality_id NUMBER CONSTRAINT fk_individuals_national REFERENCES nationality(id) ON DELETE SET NULL,
);


CREATE TABLE news (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_news,
    title VARCHAR2(255) NOT NULL,
    content CLOB NOT NULL,
    image BLOB,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE events (
    id NUMBER GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY CONSTRAINT pk_events,
    title VARCHAR2(255) NOT NULL,
    content CLOB NOT NULL,
    image BLOB,
    start_date TIMESTAMP NOT NULL,
    end_date TIMESTAMP NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);