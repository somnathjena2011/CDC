/*CREATE TABLE RegUser(RNo int, RName varchar(20),  ROccu varchar(10),  Age int, HighestQual varchar(5), PRIMARY KEY(RNo)); 

CREATE TABLE Faculty( FId int, ResearchArea varchar(4), FDept varchar(3), HighestQual varchar(5), PRIMARY KEY(FId), FOREIGN KEY fk_std_0(FId) REFERENCES RegUser(RNo)); 

CREATE TABLE Course (CId int, CName varchar(10), CDuration varchar(10), CDept varchar(3)  ,  FId int,PRIMARY KEY(CId), FOREIGN KEY fk_std_1(FId) REFERENCES Faculty(FId));

CREATE TABLE Prerequisite (CId int, PreqCId int, FOREIGN KEY fk_std2(  CId) REFERENCES Course (CId),FOREIGN KEY fk_std3(  PreqCId) REFERENCES Course (CId),   PRIMARY KEY(CId, PreqCId)); 

CREATE TABLE CourseReg( RNo int, CId int, Score int, PRIMARY KEY(RNo, CId), FOREIGN KEY fk_std4(  RNo) REFERENCES RegUser (RNo),FOREIGN KEY fk_std5(  CId) REFERENCES Course ( CId));*/

-- C.7
SELECT RU.RNo, RU.RName,C.CId,C.CName
FROM RegUser AS RU, Course AS C, CourseReg AS CR
WHERE RU.RNo=CR.RNo AND C.CId=CR.CId
AND RU.RNo NOT IN
(SELECT DR.RNo FROM CourseReg AS DR
WHERE DR.CId IN
(SELECT P.CId FROM Prerequisite AS P
GROUP BY P.CId
HAVING COUNT(P.PreqCId)=1));

-- D.7
SELECT C.CId,C.CName,C.CDuration,F.FId,RU.RName,F.FDept,F.ResearchArea,RU.HighestQual
FROM Course AS C NATURAL JOIN Faculty AS F 
JOIN RegUser AS RU ON F.FId=RU.RNo
WHERE C.CDuration<>'LONG'
AND RU.HighestQual<>'PHD'
AND F.FDept='ECE'
AND F.ResearchArea='DBMS';

-- E.7
SELECT R.RNo, R.RName
FROM RegUser AS R NATURAL JOIN CourseReg AS C
WHERE R.ROccu='STUDENT' AND R.RName LIKE 'A%'
GROUP BY R.RNo, R.RName
HAVING COUNT(C.CId)>=2;

-- F.7
SELECT C.CId,C.CName,C.CDept
FROM Course AS C 
WHERE C.CDept IN ('CS','ECE')
AND C.CId NOT IN 
(SELECT PR.CId
FROM Prerequisite AS PR JOIN Course AS D
ON PR.PreqCId=D.CId
WHERE D.CDuration='LONG');

-- G.7
SELECT F.FId,C.CId,F.ResearchArea
FROM Faculty AS F NATURAL JOIN Course AS C
WHERE 
(SELECT COUNT(D.CId)
FROM Course AS D
WHERE D.CDept='CSE' AND D.CDuration='LONG' 
AND D.FId=F.FId)>=2;

-- I.7
SELECT RU.RNo,RU.RName,RU.ROccu,RU.HighestQual,F.FDept,
F.ResearchArea,Co.CId,Co.CName,Co.CDuration
FROM RegUser AS RU JOIN Faculty AS F ON RU.RNo=F.FId
NATURAL JOIN Course AS Co
WHERE F.FDept='EE' AND F.ResearchArea='ML'
AND RU.HighestQual='PHD'
AND (SELECT COUNT(C.CId)
FROM Course AS C WHERE C.CDuration='SHORT'
AND C.FId=F.FId)>3;

-- M.7
SELECT F.FId,RU.RName,C.CId,C.CName
FROM Faculty AS F NATURAL JOIN Course AS C
JOIN RegUser AS RU ON F.FId=RU.RNo
WHERE RU.HighestQual='PHD'
AND F.FDept='CS'
AND (SELECT COUNT(P.PreqCId) FROM Prerequisite AS P
     WHERE P.CId=C.CId)>1;

-- O.7
SELECT C.CId, C.CName, 
(SELECT MIN(CR.Score) FROM CourseReg AS CR 
NATURAL JOIN RegUser AS RU WHERE RU.HighestQual='MTECH'
AND CR.CId=C.CId)/
(SELECT CR.Score FROM CourseReg AS CR 
NATURAL JOIN RegUser AS RU WHERE RU.HighestQual='MTECH'
AND CR.CId=C.CId 
AND (SELECT COUNT(CG.CId) 
     FROM CourseReg AS CG 
     NATURAL JOIN RegUser AS RG WHERE RG.HighestQual='MTECH'
     AND CG.CId=C.CId
     AND CG.Score<CR.Score)=1
LIMIT 1) 
AS Ratio
FROM Course AS C;

-- P.7
SELECT C.CName, 
(SELECT MAX(CR.Score) FROM CourseReg AS CR 
WHERE CR.CId=C.CId) AS max,
(SELECT AVG(CR.Score) FROM CourseReg AS CR
WHERE CR.CId=C.CId) AS mean,
(SELECT STDDEV(CR.Score) FROM CourseReg AS CR
WHERE CR.CId=C.CId) AS stddev
FROM Course AS C;