CREATE TABLE patient(
	patient_id int PRIMARY KEY,
	name varchar(200) NOT NULL,
	house_no int,
	street varchar(200),
	pincode numeric(6,0),
	state varchar(200),
	gender varchar(10) NOT NULL CHECK(gender IN ('male','female','other')),
	dob DATE NOT NULL
);

CREATE TABLE phone(
	patient_id int,
	phone_no numeric(10,0),
	PRIMARY KEY(patient_id,phone_no),
	FOREIGN KEY(patient_id) REFERENCES patient(patient_id)
);

CREATE TABLE department(
	department_code int,
	dept_name varchar(200) NOT NULL UNIQUE,
	hod varchar(200),
	wards int DEFAULT 0,
	PRIMARY KEY(department_code)
);

CREATE TABLE doctor(
	doctor_id int PRIMARY KEY,
	name varchar(200) NOT NULL,
	dob DATE NOT NULL,
	degree varchar(200),
	department_code int NOT NULL,
	FOREIGN KEY(department_code) REFERENCES department(department_code)
);

CREATE TABLE admission(
	patient_id int,
	doctor_id int,
	date_of_admission DATE,
	date_of_release DATE,
	PRIMARY KEY(patient_id,doctor_id,date_of_admission),
	FOREIGN KEY(patient_id) REFERENCES patient(patient_id),
	FOREIGN KEY(doctor_id) REFERENCES doctor(doctor_id)
);

CREATE TABLE dept_admission(
	patient_id int,
	department_code int,
	PRIMARY KEY(patient_id,department_code),
	FOREIGN KEY(patient_id) REFERENCES patient(patient_id),
	FOREIGN KEY(department_code) REFERENCES department(department_code)
);

-- 1
SELECT DISTINCT P.patient_id, P.name AS patient, D.doctor_id, D.name AS doctor
FROM patient AS P, admission AS A, doctor AS D
WHERE A.patient_id=P.patient_id
AND A.doctor_id=D.doctor_id
ORDER BY D.doctor_id;

-- ALTERNATE
SELECT DISTINCT P.patient_id, P.name AS patient, D.doctor_id, D.name AS doctor
FROM doctor AS D NATURAL LEFT OUTER JOIN
(patient AS P NATURAL JOIN admission AS A)
ORDER BY D.doctor_id;

-- 2
SELECT DISTINCT P.patient_id, P.name AS patient, D.doctor_id, D.name AS doctor
FROM patient AS P, doctor AS D, admission AS A 
WHERE A.patient_id=P.patient_id
AND A.doctor_id=D.doctor_id
AND A.date_of_release IS NULL
ORDER BY D.doctor_id;

-- 3
SELECT DISTINCT P.patient_id, P.name AS patient, D.doctor_id, D.name AS doctor
FROM patient AS P, doctor AS D, admission AS A 
WHERE A.patient_id=P.patient_id
AND A.doctor_id=D.doctor_id
AND P.patient_id IN 
(SELECT DA.patient_id 
FROM dept_admission AS DA
GROUP BY DA.patient_id
HAVING COUNT(DISTINCT DA.department_code)>1);

-- 4
SELECT DISTINCT P.patient_id, P.name AS patient, D.doctor_id, D.name AS doctor
FROM patient AS P, doctor AS D, admission AS A 
WHERE A.patient_id=P.patient_id
AND A.doctor_id=D.doctor_id
AND P.patient_id NOT IN 
(SELECT DA.patient_id
FROM dept_admission AS DA
WHERE DA.department_code=D.department_code);

-- 5
SELECT DISTINCT P.patient_id, P.name AS patient, D.doctor_id, D.name AS doctor
FROM patient AS P, doctor AS D, admission AS A 
WHERE A.patient_id=P.patient_id
AND A.doctor_id=D.doctor_id
AND P.patient_id IN 
(SELECT DA.patient_id 
FROM dept_admission AS DA
WHERE DA.department_code!=D.department_code);

-- 6
SELECT P.patient_id, P.name, A.date_of_admission, A.date_of_release
FROM patient AS P, admission AS A 
WHERE P.patient_id=A.patient_id
ORDER BY P.patient_id;

-- 7
SELECT D.doctor_id,D.name,COUNT(DISTINCT A.patient_id) AS count
FROM doctor AS D NATURAL LEFT OUTER JOIN admission AS A
WHERE A.date_of_release IS NULL
GROUP BY D.doctor_id, D.name ;

-- 8
SELECT DA.department_code, COUNT(DISTINCT DA.patient_id) AS count
FROM dept_admission AS DA, department AS D 
WHERE DA.department_code=D.department_code
AND D.wards>5
AND D.department_code IN 
(SELECT E.department_code
FROM dept_admission AS E
GROUP BY E.department_code
HAVING COUNT(DISTINCT E.patient_id)>2)
GROUP BY (DA.department_code);

/*
INSERT INTO patient(patient_id,name,gender,dob)
VALUES(1,'Sonu','male','2001-04-12');
INSERT INTO patient(patient_id,name,gender,dob)
VALUES(2,'Jeko','male','2001-04-12');
INSERT INTO patient(patient_id,name,gender,dob)
VALUES(3,'Jena','male','2001-04-12');

INSERT INTO department VALUES(1,'A',NULL,1);
INSERT INTO department VALUES(2,'B',NULL,2);
INSERT INTO department VALUES(3,'C',NULL,3);
INSERT INTO department VALUES(4,'D',NULL,4);
INSERT INTO department VALUES(5,'E',NULL,5);
INSERT INTO department VALUES(6,'F',NULL,6);
INSERT INTO department VALUES(7,'G',NULL,7);
INSERT INTO department VALUES(8,'H',NULL,8);
INSERT INTO department VALUES(9,'I',NULL,9);

INSERT INTO doctor VALUES
(1,'A','2000-01-01',NULL,1);
INSERT INTO doctor VALUES
(2,'B','2000-01-01',NULL,1);
INSERT INTO doctor VALUES
(3,'C','2000-01-01',NULL,3);
INSERT INTO doctor VALUES
(4,'D','2000-01-01',NULL,3);
INSERT INTO doctor VALUES
(5,'E','2000-01-01',NULL,5);
INSERT INTO doctor VALUES
(6,'F','2000-01-01',NULL,5);
INSERT INTO doctor VALUES
(7,'G','2000-01-01',NULL,7);
INSERT INTO doctor VALUES
(8,'H','2000-01-01',NULL,7);
INSERT INTO doctor VALUES
(9,'I','2000-01-01',NULL,9);

INSERT INTO admission VALUES(1,1,'2000-01-01',NULL);
INSERT INTO admission VALUES(1,1,'2010-01-01',NULL);
INSERT INTO admission VALUES(2,1,'2000-01-01',NULL);
INSERT INTO admission VALUES(2,1,'2010-01-01','2000-01-01');
INSERT INTO admission VALUES(3,1,'2000-01-01','2000-01-01');

INSERT INTO dept_admission VALUES(1,1);
INSERT INTO dept_admission VALUES(1,2);
INSERT INTO dept_admission VALUES(1,6);
INSERT INTO dept_admission VALUES(2,6);
INSERT INTO dept_admission VALUES(3,6);
INSERT INTO dept_admission VALUES(2,7);
*/