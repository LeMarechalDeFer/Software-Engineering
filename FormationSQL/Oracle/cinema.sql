-- DROP TABLE Artiste CASCADE CONSTRAINTS;
-- DROP TABLE Cinema CASCADE CONSTRAINTS;
-- DROP TABLE Film CASCADE CONSTRAINTS;
-- DROP TABLE Role CASCADE CONSTRAINTS;
-- DROP TABLE Salle CASCADE CONSTRAINTS;
-- DROP TABLE Seance CASCADE CONSTRAINTS;

-- DROP TABLE Artiste CASCADE;
-- DROP TABLE Cinema CASCADE;
-- DROP TABLE Film CASCADE;
-- DROP TABLE Role CASCADE;
-- DROP TABLE Salle CASCADE;
-- DROP TABLE Seance CASCADE;


CREATE TABLE Artiste ( 
   Nom varchar(20) constraint pk_artiste primary key, 
   Prenom varchar(15), 
   Annee_naissance decimal(4,0) 
    
);

CREATE TABLE Cinema ( 
   Nom_cinema varchar(10) constraint pk_cinema primary key, 
   Arrondissement decimal(2,0), 
   Adresse varchar(30) 
    
);

CREATE TABLE Film ( 
   ID_film decimal(10,0) constraint pk_film primary key, 
   Titre varchar(30), 
   Annee decimal(4,0), 
   Nom_Realisateur varchar(20) 
   );

CREATE TABLE Role ( 
   Nom_Role varchar(20) NOT NULL, 
   ID_film decimal(10,0)  constraint fk_film references Film(ID_film),  
   Nom_acteur varchar(20) constraint fk_acteur references Artiste(Nom),    
    
   constraint pk_role primary key (Nom_acteur,ID_film) 
);

CREATE TABLE Salle ( 
   No_salle decimal(2,0) constraint pk_salle primary key,   
   Nom_cinema constraint fk_cinema references Cinema(Nom_cinema),        
   Climatise char(1), 
   Capacite decimal(4,0)    
);

CREATE TABLE Seance ( 
   No_seance decimal(2,0) constraint pk_séance primary key, 
   Nom_cinema varchar(10) constraint fk2_cinema references Cinema(Nom_cinema),  
   No_salle decimal(2,0) constraint fk_salle  references Salle(No_salle ),  
   ID_film decimal(10,0) constraint fk2_film references Film(ID_film),    
   Heure_debut decimal(4,2), 
   Heure_fin decimal(4,2)   
    
);
--------- Insertion de données dans Artiste-------------------
INSERT INTO Artiste VALUES( 'Allen', 'Woody', '1938');

INSERT INTO Artiste VALUES( 'Lynch', 'David', '1946');

INSERT INTO Artiste VALUES( 'Kusturica', 'Emir', '1959');

INSERT INTO Artiste VALUES( 'Lang', 'Fritz', '1899');

INSERT INTO Artiste VALUES( 'Eastwood', 'Clint', '1932');

INSERT INTO Artiste VALUES( 'Hitchcock', 'Alfred', '1898');

INSERT INTO Artiste VALUES( 'Kubrick', 'Stanley', '1935');

INSERT INTO Artiste VALUES( 'Curtis', 'Michael', '1902');

INSERT INTO Artiste VALUES( 'Stewart', 'James', '1911');

INSERT INTO Artiste VALUES( 'Novak', 'Kim', NULL);

INSERT INTO Artiste VALUES( 'Hunt', 'Greg', '1950');

INSERT INTO Artiste VALUES( 'Tarantino', 'Quentin', '1948');

INSERT INTO Artiste VALUES( 'Willis', 'Bruce', '1952');

INSERT INTO Artiste VALUES( 'Spielberg', 'Steven', '1943');

INSERT INTO Artiste VALUES( 'Hudson', 'Hugh', NULL);

INSERT INTO Artiste VALUES( 'Gillian', 'Terry', '1944');

INSERT INTO Artiste VALUES( 'Truffaut', 'Francois', '1938');

INSERT INTO Artiste VALUES( 'Lambert', 'Christophe', '1953');

INSERT INTO Artiste VALUES( 'Keitel', 'Harvey', '1940');

INSERT INTO Artiste VALUES( 'Woo', 'John', '1951');

INSERT INTO Artiste VALUES( 'Travolta', 'John', '1953');

INSERT INTO Artiste VALUES( 'Cage', 'Nicolas', '1954');

INSERT INTO Artiste VALUES( 'DiCaprio', 'Leonardo', '1973');

INSERT INTO Artiste VALUES( 'Cameron', 'James', '1943');

INSERT INTO Artiste VALUES( 'Cruise', 'Tom', '1960');

INSERT INTO Artiste VALUES( 'De Palma', 'Brian', '1953');

INSERT INTO Artiste VALUES( 'Depp', 'Johnny', '1967');

INSERT INTO Artiste VALUES( 'Ricci', 'Christina', '1974');

INSERT INTO Artiste VALUES( 'Burton', 'Tim', '1958');

----------------------Insertion de données dans Cinema--------------

INSERT INTO Cinema VALUES( 'Rex', '2', '22 Bd Poissoniere');

INSERT INTO Cinema VALUES( 'Kino', '15', '3 Bd Raspail');

INSERT INTO Cinema VALUES( 'Nations', '12', '3 Rue de Reuilly');

INSERT INTO Cinema VALUES( 'Halles', '1', 'Forum des Halles');

---------------------Insertion de données dans Film-----------------

INSERT INTO Film VALUES( '10', 'Annie Hall', '1977', 'Allen');

INSERT INTO Film VALUES( '57', 'Brazil', '1984', 'Gillian');

INSERT INTO Film VALUES( '5', 'Underground', '1995', 'Kusturica');

INSERT INTO Film VALUES( '38', 'Metropolis', '1926', 'Lang');

INSERT INTO Film VALUES( '45', 'Impitoyable', '1992', 'Eastwood');

INSERT INTO Film VALUES( '65', 'Vertigo', '1958', 'Hitchcock');

INSERT INTO Film VALUES( '7', 'Shining', '1980', 'Kubrick');

INSERT INTO Film VALUES( '6', 'Psychose', '1960', 'Hitchcock');

INSERT INTO Film VALUES( '3', 'Twin Peaks', '1990', 'Lynch');

INSERT INTO Film VALUES( '90', 'Casablanca', '1942', 'Curtis');

INSERT INTO Film VALUES( '85', 'Greystocke', '1984', 'Hudson');

INSERT INTO Film VALUES( '89', 'Le dernier metro', '1980', 'Truffaut');

INSERT INTO Film VALUES( '1', 'Reservoir Dogs', '1992', 'Tarantino');

INSERT INTO Film VALUES( '43', 'Manhattan', '1979', 'Allen');

INSERT INTO Film VALUES( '11', 'Jurassic Park', '1992', 'Spielberg');

INSERT INTO Film VALUES( '32', 'Rencontres du 3eme type', '1978', 'Spielberg');

INSERT INTO Film VALUES( '33', 'Piege de cristal', '1990', 'Hunt');

INSERT INTO Film VALUES( '34', 'Une journee en enfer', '1994', 'Hunt');

INSERT INTO Film VALUES( '35', '48 minutes pour vivre', '1992', 'Hunt');

INSERT INTO Film VALUES( '73', 'Pulp Fiction', '1995', 'Tarantino');

INSERT INTO Film VALUES( '101', 'Broken Arrow', '1996', 'Woo');

INSERT INTO Film VALUES( '102', 'Volte-Face', '1997', 'Woo');

INSERT INTO Film VALUES( '104', 'Titanic', '1998', 'Cameron');

INSERT INTO Film VALUES( '135', 'Mission Impossible 2', '2000', 'Woo');

INSERT INTO Film VALUES( '136', 'Mission Impossible', '1997', 'De Palma');

INSERT INTO Film VALUES( '142', 'Edward scissorhands', '1990', 'Burton');

INSERT INTO Film VALUES( '141', 'Sleepy Hollow', '1999', 'Burton');

------------------------Insertion de données Role---------------------

INSERT INTO Role VALUES( 'Bernard', '32', 'Truffaut');

INSERT INTO Role VALUES( 'Davis', '43', 'Allen');

INSERT INTO Role VALUES( 'Tarzan', '85', 'Lambert');

INSERT INTO Role VALUES( 'Ferguson', '65', 'Stewart');

INSERT INTO Role VALUES( 'Elster', '65', 'Novak');

INSERT INTO Role VALUES( 'Jonas', '10', 'Allen');

INSERT INTO Role VALUES( 'McLane', '33', 'Willis');

INSERT INTO Role VALUES( 'McLane', '34', 'Willis');

INSERT INTO Role VALUES( 'McLane', '35', 'Willis');

INSERT INTO Role VALUES( 'Mr Brown', '1', 'Tarantino');

INSERT INTO Role VALUES( 'Munny', '45', 'Eastwood');

INSERT INTO Role VALUES( 'Mr White', '1', 'Keitel');

INSERT INTO Role VALUES( 'Wolf', '73', 'Keitel');

INSERT INTO Role VALUES( 'Coolidge', '73', 'Willis');

INSERT INTO Role VALUES( 'Vega', '73', 'Travolta');

INSERT INTO Role VALUES( 'Deakins', '101', 'Travolta');

INSERT INTO Role VALUES( 'Archer', '102', 'Travolta');

INSERT INTO Role VALUES( 'Troy', '102', 'Cage');

INSERT INTO Role VALUES( 'Dowson', '104', 'DiCaprio');

INSERT INTO Role VALUES( 'Howard', '135', 'Cruise');

INSERT INTO Role VALUES( 'Howard', '136', 'Cruise');

INSERT INTO Role VALUES( 'Crane', '141', 'Depp');

INSERT INTO Role VALUES( 'Edward', '142', 'Depp');

INSERT INTO Role VALUES( 'Van Tassel', '141', 'Ricci');

-------------------------Insertion de données dans Salle-----------------

INSERT INTO Salle VALUES( '1','Rex','O', '150');

INSERT INTO Salle VALUES( '2','Rex', 'O', '100');

INSERT INTO Salle VALUES( '3', 'Rex', 'N', '80');

INSERT INTO Salle VALUES( '4','Rex',  'N', '80');

INSERT INTO Salle VALUES( '5','Kino', 'N', '280');

INSERT INTO Salle VALUES( '6','Kino', 'O', '120');

INSERT INTO Salle VALUES( '7', 'Kino', 'O', '130');

INSERT INTO Salle VALUES( '8','Nations', 'O', '130');

INSERT INTO Salle VALUES( '9','Nations', 'N', '90');

INSERT INTO Salle VALUES( '10','Nations',  'N', '60');

INSERT INTO Salle VALUES( '11', 'Halles', 'O', '75');

INSERT INTO Salle VALUES( '12', 'Halles','N', '60');

INSERT INTO Salle VALUES( '13','Halles',  'N', '60');

-------------------Insertion de données dans Seance--------------------------

INSERT INTO Seance VALUES( '1','Rex', '1',  '1', '8.00', '9.00');

INSERT INTO Seance VALUES( '2', 'Rex', '1','6', '9.00', '10.00');

INSERT INTO Seance VALUES( '3','Rex', '2', '34', '7.00', '8.00' );

INSERT INTO Seance VALUES( '4','Rex', '2', '34','5.00', '6.00' );

INSERT INTO Seance VALUES( '5','Rex', '2', '7', '4.00', '5.00' );

INSERT INTO Seance VALUES( '6','Rex', '2', '65', '3.00', '4.00');

INSERT INTO Seance VALUES( '7','Rex', '3', '11', '9.00', '10.00');

INSERT INTO Seance VALUES( '8','Rex', '3', '11', '11.00', '12.00');

INSERT INTO Seance VALUES( '9','Rex', '3', '11', '13.00', '14.00');

INSERT INTO Seance VALUES( '10','Rex', '4', '38', '15.00', '16.00' );

INSERT INTO Seance VALUES( '11','Rex', '4',  '38','16.00', '17.00');

INSERT INTO Seance VALUES( '12','Rex', '4',  '38','9.00', '10.00');

INSERT INTO Seance VALUES( '13','Kino', '1', '34', '9.00', '10.00');

INSERT INTO Seance VALUES( '14','Kino', '1',  '73','10.00', '11.00');

INSERT INTO Seance VALUES( '15','Kino', '1',  '34','12.00', '13.00');

INSERT INTO Seance VALUES( '16','Kino', '2',   '43','9.00', '10.00');

INSERT INTO Seance VALUES( '18','Kino', '2',  '7','18.00', '19.00');

INSERT INTO Seance VALUES( '19','Kino', '2',  '43','20.00', '21.00');

INSERT INTO Seance VALUES( '20','Kino', '3',  '101','21.00', '22.00');

INSERT INTO Seance VALUES( '21','Kino', '3',  '102','22.00', '23.00');

INSERT INTO Seance VALUES( '22','Kino', '3',  '104','00.00', '1.00');

INSERT INTO Seance VALUES( '23','Kino', '3',  '104','1.00', '2.00');

INSERT INTO Seance VALUES( '24', 'Nations', '1','65', '2.00', '3.00');

INSERT INTO Seance VALUES( '25','Nations', '1',  '65','3.00', '4.00');

INSERT INTO Seance VALUES( '26','Nations', '1', '65', '5.00', '6.00');

INSERT INTO Seance VALUES( '27', 'Nations', '2', '43','7.00', '8.00');

INSERT INTO Seance VALUES( '28','Nations', '2', '43', '9.00', '10.00');

INSERT INTO Seance VALUES( '29','Nations', '2','43',  '10.00', '11.00');

INSERT INTO Seance VALUES( '30','Nations', '3', '7', '1.00', '2.00');

INSERT INTO Seance VALUES( '31','Nations', '3', '7', '3.00', '4.00');

INSERT INTO Seance VALUES( '32','Nations', '3', '7', '4.00', '5.00');

INSERT INTO Seance VALUES( '33','Halles', '1', '32', '5.00', '6.00');

INSERT INTO Seance VALUES( '34','Halles', '1', '32', '7.00', '8.00');

INSERT INTO Seance VALUES( '35', 'Halles', '1', '32','9.00', '10.00');

INSERT INTO Seance VALUES( '36','Halles', '2',   '5','11.00', '12.00');

INSERT INTO Seance VALUES( '38','Halles', '2',  '5','13.00', '14.00');

INSERT INTO Seance VALUES( '39','Halles', '2', '45', '15.00', '16.00');

INSERT INTO Seance VALUES( '40','Halles', '3', '3', '17.00', '18.00');

INSERT INTO Seance VALUES( '41', 'Halles', '3', '3','20.00', '21.00');

INSERT INTO Seance VALUES( '42','Halles', '3','3',  '3.00', '4.00');
---------------------------------------------------

select * From Artiste;

select * From Cinema;

select * From Film;

select * From Role;

select * From Salle;

select * From Seance;