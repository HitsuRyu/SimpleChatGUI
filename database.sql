-- MySQL dump 10.13  Distrib 8.0.31, for Linux (x86_64)
--
-- Host: localhost    Database: SimpleChat_db
-- ------------------------------------------------------
-- Server version	8.0.31-0ubuntu0.22.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Login_Pwd`
--

DROP TABLE IF EXISTS `Login_Pwd`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Login_Pwd` (
  `Login` int NOT NULL,
  `Password` varchar(40) DEFAULT NULL,
  `Permission` varchar(2) DEFAULT NULL,
  PRIMARY KEY (`Login`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Login_Pwd`
--

LOCK TABLES `Login_Pwd` WRITE;
/*!40000 ALTER TABLE `Login_Pwd` DISABLE KEYS */;
INSERT INTO `Login_Pwd` VALUES (1000,'30274c47903bd1bac7633bbf09743149ebab805f','rw'),(1001,'6cadbca0a4c252abdeba4b2a53420f163ec32ce3','r'),(1002,'36f1372b5d5550695bfd83f4c97dac4ecdff5b80','w'),(1003,'b87ed8d4b40264bc6026b7e782fed5686a51fb80','rw'),(1004,'33464fdeb5d05b4701c3506284543292783086f5','r'),(1005,'9ba97b763f34c8904f202854a82f63b12169a395','w'),(1006,'e21dfc1b2adaa61f78992d42b085508f13147efc','rw'),(1007,'a203fafded5227a15d51e41084ee236187bd4ca1','r'),(1008,'7584b4d55131d42b8f026f109ddafaed1725187b','w'),(1009,'be40a26e2411dd9ec88218c0f53b9b8966c98400','rw'),(1010,'7c4a8d09ca3762af61e59520943dc26494f8941b','r'),(1050,'3e1a39bb5fe1aa10cfa68fa1286d4a6421eb8302','w'),(1337,'b1b3773a05c0ed0176787a4f1574ff0075f7521e','rw'),(5555,'f7a9e24777ec23212c54d7a350bc5bea5477fdbb','r'),(8080,'30274c47903bd1bac7633bbf09743149ebab805f','w'),(9999,'b1b3773a05c0ed0176787a4f1574ff0075f7521e','rw');
/*!40000 ALTER TABLE `Login_Pwd` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Message`
--

DROP TABLE IF EXISTS `Message`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Message` (
  `MessageID` int NOT NULL AUTO_INCREMENT,
  `Login` int NOT NULL,
  `Timestamp` varchar(20) NOT NULL,
  `MessageData` text NOT NULL,
  PRIMARY KEY (`MessageID`,`Login`),
  KEY `MesKey_1` (`Login`),
  CONSTRAINT `Message_ibfk_1` FOREIGN KEY (`Login`) REFERENCES `User_Data` (`Login`)
) ENGINE=InnoDB AUTO_INCREMENT=66 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Message`
--

LOCK TABLES `Message` WRITE;
/*!40000 ALTER TABLE `Message` DISABLE KEYS */;
INSERT INTO `Message` VALUES (34,1337,'13:57','Test message'),(35,1010,'10:10','debugging'),(36,1010,'10:10','debugging'),(37,1010,'10:10','debugging'),(38,1337,'2022','new debugging'),(39,1337,'2022','new debugging'),(40,1337,'2022','new debugging'),(41,1337,'2022','test'),(42,1337,'2022','another test'),(43,1337,'2022','t1'),(44,1337,'2022','t2'),(45,1337,'2022','t3'),(46,1337,'2022.10.27 14:10:9','t4'),(47,1337,'2022.10.27 14:10:14','t5'),(48,1337,'2022.10.27 14:10:26','НАКОНЕЦ ТО ОНО РАБОТАЕТ!'),(49,5555,'2022.10.27 14:16:36','Проверка работы программы с новым пользователем'),(50,1337,'2022.10.27 14:20:16','test 5555'),(51,1337,'2022.10.27 14:57:14','1231241'),(52,1337,'2022.10.27 15:29:15','qwer'),(53,1000,'2022.10.27 15:48:30','another machine test'),(54,1000,'2022.10.27 17:41:34','Тестовое сообщение '),(55,1000,'2022.10.28 0:12:34','asdasdfasfasgaagasf'),(56,1000,'2022.10.28 0:12:51','GrafVorobay'),(57,1337,'2022.10.28 0:13:44','ASSALAMU ALEYKUM BRAT'),(58,1009,'2022.10.28 1:16:25','REDZED - COUNTING DAYS TILL S*I*I*D*\n'),(59,1009,'2022.10.28 1:16:29','lol'),(60,1000,'2022.10.28 20:55:13','asagkljhbsdfklgjhdslkjgsfdgdsgsd'),(61,1337,'2022.10.28 21:17:57','asdasdasdasda'),(62,1337,'2022.10.28 21:19:12','\'; SELECT * FROM UUID_Table;'),(63,1000,'2022.10.31 22:34:51','test RW'),(64,1002,'2022.10.31 22:36:0','test w'),(65,1000,'2022.10.31 22:45:15','Тест прав пользователя на чтение и запись!');
/*!40000 ALTER TABLE `Message` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Product_Key`
--

DROP TABLE IF EXISTS `Product_Key`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Product_Key` (
  `ProdKey` varchar(40) NOT NULL,
  PRIMARY KEY (`ProdKey`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Product_Key`
--

LOCK TABLES `Product_Key` WRITE;
/*!40000 ALTER TABLE `Product_Key` DISABLE KEYS */;
INSERT INTO `Product_Key` VALUES ('07eeb37d335e5de9cda89f870c4394dd8c65bc20'),('0de35fb19144c27385784df3cf440d37a9edf2bd'),('1d0250311806b9196b60dd1dad3815621198445f'),('24cb50a586ab13a81fcc6c68ec4cb75d26a4f72c'),('47bb825c014b16faba2d72ecc4a512d9f8a28f8c'),('6cd9d5ac0f45ed1e5c2ed34da1a261059999040e'),('78a366d28b5ff366d18f6849a523595eef4f1eee'),('7ffc4c6b5184eab65992b1dbbb33388615e74f66'),('a23f19b9105e43b794203d046c7beb0000f90c50'),('b4368c1d313a0e733f932fb56d8902f0a02b280a');
/*!40000 ALTER TABLE `Product_Key` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `UUID_Table`
--

DROP TABLE IF EXISTS `UUID_Table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `UUID_Table` (
  `ProdKey` varchar(40) NOT NULL,
  `UUID` varchar(32) NOT NULL,
  PRIMARY KEY (`ProdKey`),
  CONSTRAINT `UUID_Table_ibfk_1` FOREIGN KEY (`ProdKey`) REFERENCES `Product_Key` (`ProdKey`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `UUID_Table`
--

LOCK TABLES `UUID_Table` WRITE;
/*!40000 ALTER TABLE `UUID_Table` DISABLE KEYS */;
INSERT INTO `UUID_Table` VALUES ('07eeb37d335e5de9cda89f870c4394dd8c65bc20','2a7428458da7474c81169e4d51424f0');
/*!40000 ALTER TABLE `UUID_Table` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `User_Data`
--

DROP TABLE IF EXISTS `User_Data`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `User_Data` (
  `Login` int NOT NULL,
  `Name` varchar(20) DEFAULT NULL,
  `LastName` varchar(20) DEFAULT NULL,
  `Phone` varchar(11) DEFAULT NULL,
  `Email` varchar(20) DEFAULT NULL,
  `Address` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`Login`),
  CONSTRAINT `User_Data_ibfk_1` FOREIGN KEY (`Login`) REFERENCES `Login_Pwd` (`Login`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `User_Data`
--

LOCK TABLES `User_Data` WRITE;
/*!40000 ALTER TABLE `User_Data` DISABLE KEYS */;
INSERT INTO `User_Data` VALUES (1000,'Ahmed','Aliev','81234567890','ahmed@aliev.ru','Grozny'),(1001,'Maria','Botkina','89001002030','ma@bot.ru','Ekatirinburg'),(1002,'Nikita','Chekhlov','89052502345','nik@chek.ru','Rostov'),(1003,'Sergey','Selivanov','89305556677','TopProger@in.MAI','MAI'),(1004,'Anastasia','Mirnaya','80019411945','nastya@onlyfans.com','St.'),(1005,'Galina','Mirnaya','89042348763','school@spb.ru','St.'),(1006,'Kirill','Mukhin','87776665544','kirill@muk.ru','Moscow'),(1007,'Nikolay','Sobolev','89006003545','liberaha@begi.ru','Not'),(1008,'Vlad','Stolov','85607896374','dead@inside.ru','Graveyard'),(1009,'Natalya','Abramova','87663235678','ahs@inyaz.ru','MAI'),(1010,'Test','Test','00000000000','test','test'),(1050,'User','User','88005553535','user@test.com','test'),(1337,'kek','lol','11111111111','ererere','afasdsa'),(5555,'user0','user1','11111111111','aaaaaaaaaaaaaaaaaaaa','aaaaaaaaaaaaaaaaa'),(8080,'1','1','11111111111','1','1'),(9999,'Lev','Garminov','88005553535','lev@garminov.com','Moscow');
/*!40000 ALTER TABLE `User_Data` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-10-31 22:51:59
