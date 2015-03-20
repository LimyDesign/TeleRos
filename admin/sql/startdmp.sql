-- MySQL dump 10.10
--
-- Host: localhost    Database: tel
-- ------------------------------------------------------
-- Server version	5.0.26

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Temporary table structure for view `abonent`
--


DROP TABLE IF EXISTS `acccall`;
CREATE TABLE `acccall` (
  `date` timestamp NOT NULL default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP,
  `time` varchar(4) NOT NULL,
  `code-used` varchar(4) NOT NULL,
  `out-crt-id` varchar(3) NOT NULL,
  `in-trk-code` varchar(4) NOT NULL,
  `in-crt-id` varchar(3) NOT NULL,
  `clg-num-in-tac` varchar(10) NOT NULL,
  `cond-code` varchar(1) NOT NULL,
  `frl` varchar(1) NOT NULL,
  `sec-dur` int(11) NOT NULL,
  `dialed-num` varchar(18) NOT NULL,
  `node-num` varchar(2) NOT NULL,
  `id` int(11) NOT NULL auto_increment,
  PRIMARY KEY  (`id`),
  KEY `clg-num-in-tac` (`clg-num-in-tac`),
  KEY `dialed-num` (`dialed-num`),
  KEY `date` (`date`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `acccall`
--

LOCK TABLES `acccall` WRITE;
/*!40000 ALTER TABLE `acccall` DISABLE KEYS */;
/*!40000 ALTER TABLE `acccall` ENABLE KEYS */;
UNLOCK TABLES;


--
-- Table structure for table `bands`
--

DROP TABLE IF EXISTS `bands`;
CREATE TABLE `bands` (
  `BandId` int(11) NOT NULL auto_increment,
  `Name` varchar(100) NOT NULL,
  `Note` varchar(100) NOT NULL,
  PRIMARY KEY  (`BandId`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `bands`
--

LOCK TABLES `bands` WRITE;
/*!40000 ALTER TABLE `bands` DISABLE KEYS */;
INSERT INTO `bands` VALUES (0,'Системная зона','');
/*!40000 ALTER TABLE `bands` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `departs`
--

DROP TABLE IF EXISTS `departs`;
CREATE TABLE `departs` (
  `DepId` int(11) NOT NULL auto_increment,
  `Name` varchar(100) NOT NULL,
  `Note` varchar(100) NOT NULL,
  PRIMARY KEY  (`DepId`),
  KEY `DepId` (`DepId`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `departs`
--

LOCK TABLES `departs` WRITE;
INSERT INTO `departs` VALUES ('0','Подразделение не определено','не удалять системная запись');
/*!40000 ALTER TABLE `departs` DISABLE KEYS */;
/*!40000 ALTER TABLE `departs` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `masks`
--

DROP TABLE IF EXISTS `masks`;
CREATE TABLE `masks` (
  `MaskId` int(11) NOT NULL auto_increment,
  `PhoneMask` varchar(30) NOT NULL,
  `CallTypeId` int(11) NOT NULL,
  `BandId` int(11) NOT NULL,
  `DialedArea` varchar(100) NOT NULL,
  PRIMARY KEY  (`MaskId`),
  KEY `PhoneMask` (`PhoneMask`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `masks`
--

LOCK TABLES `masks` WRITE;
/*!40000 ALTER TABLE `masks` DISABLE KEYS */;
/*!40000 ALTER TABLE `masks` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `offices`
--

DROP TABLE IF EXISTS `offices`;
CREATE TABLE `offices` (
  `OfficeId` int(11) NOT NULL auto_increment,
  `OfficeName` varchar(100) NOT NULL,
  `Note` varchar(100) NOT NULL,
  PRIMARY KEY  (`OfficeId`),
  KEY `OfficeId` (`OfficeId`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `offices`
--

LOCK TABLES `offices` WRITE;
INSERT INTO `offices` VALUES ('0','Местоположение не определено','не удалять системная запись');
/*!40000 ALTER TABLE `offices` DISABLE KEYS */;
/*!40000 ALTER TABLE `offices` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `person`
--

DROP TABLE IF EXISTS `person`;
CREATE TABLE `person` (
  `PersonId` int(11) NOT NULL auto_increment,
  `Name` varchar(100) NOT NULL,
  `Note` varchar(100) default NULL,
  PRIMARY KEY  (`PersonId`),
  KEY `PersonId` (`PersonId`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `person`
--

LOCK TABLES `person` WRITE;
INSERT INTO `person` VALUES ('0','Абонент не определен','не удалять системная запись');
/*!40000 ALTER TABLE `person` DISABLE KEYS */;
/*!40000 ALTER TABLE `person` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `phones`
--

DROP TABLE IF EXISTS `phones`;
CREATE TABLE `phones` (
  `PhoneId` int(11) NOT NULL auto_increment,
  `PhoneNumber` varchar(10) NOT NULL,
  `OfficeId` int(11) NOT NULL,
  `PersonId` int(11) default NULL,
  `DepId` int(11) default NULL,
  PRIMARY KEY  (`PhoneId`),
  KEY `PhoneNumber` (`PhoneNumber`),
  KEY `OfficeId` (`OfficeId`),
  KEY `DepId` (`DepId`),
  KEY `PersonId` (`PersonId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `phones`
--

LOCK TABLES `phones` WRITE;
/*!40000 ALTER TABLE `phones` DISABLE KEYS */;
/*!40000 ALTER TABLE `phones` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `trunk`
--

DROP TABLE IF EXISTS `trunk`;
CREATE TABLE `trunk` (
  `idtrunk` int(11) NOT NULL auto_increment,
  `tac` varchar(3) NOT NULL,
  `trunkname` varchar(50) NOT NULL,
  PRIMARY KEY  (`idtrunk`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `trunk`
--

LOCK TABLES `trunk` WRITE;
/*!40000 ALTER TABLE `trunk` DISABLE KEYS */;
/*!40000 ALTER TABLE `trunk` ENABLE KEYS */;
UNLOCK TABLES;



alter table `phones` add index (`PhoneNumber`);
alter table `acccall` add index  (`dialed-num`);
alter table `acccall` add index  (`clg-num-in-tac`);
alter table `acccall` add index  (`date`);          
alter table `masks` add index  (`DialedArea`);      
alter table `phones`  add UNIQUE (`PhoneNumber`);   
alter table `phones`  add index  (`PersonId`);      

CREATE TABLE `accreport` (
  `id_report` int(11) NOT NULL auto_increment,
    `name` varchar(200) NOT NULL,               
      `get_rep` text NOT NULL,                    
        PRIMARY KEY  (`id_report`)                  
        ) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;
        
        
        
        
        CREATE OR REPLACE VIEW abonent AS (
        select `a`.`PhoneId` AS `PhoneId`, 
        `a`.`PhoneNumber` AS `PhoneNumber`,
        `b`.`PersonId` AS `PersonId`,      
        `b`.`Name` AS `Name`,              
        `b`.`Note` AS `PersonNote`,        
        `c`.`OfficeName` AS `OfficeName`,  
        `c`.`Note` AS `OfficeNote`,        
        `d`.`Name` AS `depatment`,         
        `d`.`Note` AS `depNote`,           
        `d`.`DepId` AS `DepId`,            
        `c`.`OfficeId` AS `OfficeId` from (((`phones` `a` join `person` `b`) join `offices` `c`) join `departs` `d`) where ((`a`.`PersonId` = `b`.`PersonId`) and (`a`.`OfficeId` = `c`.`OfficeId`) and (`a`.`DepId` = `d`.`DepId`)));                            
        
        CREATE OR REPLACE VIEW `vo_acccall` AS (
        select                                  
        `acccall`.`date` AS `date`,             
        `acccall`.`time` AS `time`,             
        `acccall`.`code-used` AS `code-used`,   
        `acccall`.`out-crt-id` AS `out-crt-id`, 
        `acccall`.`in-trk-code` AS `in-trk-code`,
        `acccall`.`in-crt-id` AS `in-crt-id`,    
        `acccall`.`clg-num-in-tac` AS `clg-num-in-tac`,
        `acccall`.`cond-code` AS `cond-code`,          
        `acccall`.`frl` AS `frl`,`acccall`.            
        `sec-dur` AS `sec-dur`,                        
        `acccall`.`dialed-num` AS `dialed-num`,        
        `acccall`.`node-num` AS `node-num`,            
        `acccall`.`id` AS `id`,                        
        `abonent`.`PhoneId` AS `PhoneId`,              
        `abonent`.`PhoneNumber` AS `PhoneNumber`,      
        `abonent`.`PersonId` AS `PersonId`,            
        `abonent`.`Name` AS `Name`,                    
        `abonent`.`PersonNote` AS `PersonNote`,        
        `abonent`.`OfficeName` AS `OfficeName`,        
        `abonent`.`OfficeNote` AS `OfficeNote`,        
        `abonent`.`depatment` AS `depatment`,          
        `abonent`.`depNote` AS `depNote`,              
        `abonent`.`DepId` AS `DepId`,                  
        `abonent`.`OfficeId` AS `OfficeId`             
        from `acccall` left join `abonent` on `acccall`.`clg-num-in-tac` = `abonent`.`PhoneNumber`);
        
        CREATE OR REPLACE VIEW `vi_acccall` AS (
        select `acccall`.`date` AS `date`,      
        `acccall`.`time` AS `time`,             
        `acccall`.`code-used` AS `code-used`,   
        `acccall`.`out-crt-id` AS `out-crt-id`, 
        `acccall`.`in-trk-code` AS `in-trk-code`,
        `acccall`.`in-crt-id` AS `in-crt-id`,
        `acccall`.`clg-num-in-tac` AS `clg-num-in-tac`,
        `acccall`.`cond-code` AS `cond-code`,
        `acccall`.`frl` AS `frl`,
        `acccall`.`sec-dur` AS `sec-dur`,
        `acccall`.`dialed-num` AS `dialed-num`,
        `acccall`.`node-num` AS `node-num`,
        `acccall`.`id` AS `id`,
        `abonent`.`PhoneId` AS `PhoneId`,
        `abonent`.`PhoneNumber` AS `PhoneNumber`,
        `abonent`.`PersonId` AS `PersonId`,
        `abonent`.`Name` AS `Name`,
        `abonent`.`PersonNote` AS `PersonNote`,
        `abonent`.`OfficeName` AS `OfficeName`,
        `abonent`.`OfficeNote` AS `OfficeNote`,
        `abonent`.`depatment` AS `depatment`,
        `abonent`.`depNote` AS `depNote`,
        `abonent`.`DepId` AS `DepId`,
        `abonent`.`OfficeId` AS `OfficeId`
        from (`acccall` left join `abonent` on((`acccall`.`dialed-num` = `abonent`.`PhoneNumber`))));
        
        



/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2009-02-20  5:25:14
