-- MySQL dump 10.13  Distrib 5.5.49, for debian-linux-gnu (i686)
--
-- Host: localhost    Database: rprb
-- ------------------------------------------------------
-- Server version	5.5.49-0ubuntu0.14.04.1

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
-- Table structure for table `activities`
--

DROP TABLE IF EXISTS `activities`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `activities` (
  `activity_id` int(6) NOT NULL AUTO_INCREMENT,
  `activity_title` varchar(50) COLLATE utf8_persian_ci DEFAULT NULL,
  `slug` varchar(50) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`activity_id`),
  UNIQUE KEY `ctitle` (`activity_title`,`slug`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=33 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `activities`
--

LOCK TABLES `activities` WRITE;
/*!40000 ALTER TABLE `activities` DISABLE KEYS */;
INSERT INTO `activities` VALUES (15,'آب','water'),(25,'آموزشی','learning'),(23,'اپتیک','optic'),(9,'الکترونیک و کامپیوتر','computer'),(4,'انرژی','energy'),(20,'بانکداری','bank'),(19,'بیمه و بازاریابی','bime'),(2,'پتروشیمی','petroshimi'),(30,'تجارت الکترونیک','tejarat'),(28,'حمل و نقل جاده ای','jadeie'),(27,'حمل و نقل ریلی','reyli'),(32,'خدمات بازرگانی',NULL),(18,'خدمات ریلی','khadamatereyli'),(17,'خدمات شهری','khadamateshahri'),(3,'خودرو','car'),(13,'دریایی','daryayi'),(24,'ربات و هوشمندسازی','robot'),(26,'سد سازی','saad'),(21,'سهام و سرمایه گذاری','saham'),(12,'سیمان','siman'),(8,'صنایع hi tech','hi-tech'),(31,'صنایع دستی',NULL),(7,'صنایع غذایی','nutrition'),(6,'صنایع نساجی','nasaji'),(22,'صنایع هوا فضا','havafaza'),(10,'فلزی','felezi'),(11,'فولاد','folad'),(14,'کشتیرانی','keshtirani'),(29,'معادن','madan'),(16,'منابع طبیعی','manabetabiee'),(1,'نفت و گاز','naftogaz'),(5,'نیروگاهی','niroogahi');
/*!40000 ALTER TABLE `activities` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `companies`
--

DROP TABLE IF EXISTS `companies`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `companies` (
  `user_id` int(6) NOT NULL,
  `code` int(10) DEFAULT NULL,
  `date` varchar(10) COLLATE utf8_persian_ci DEFAULT NULL,
  `country` varchar(15) COLLATE utf8_persian_ci DEFAULT NULL,
  `address` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `type` varchar(150) COLLATE utf8_persian_ci DEFAULT NULL,
  `isic` int(12) DEFAULT NULL,
  `capacity` varchar(150) COLLATE utf8_persian_ci DEFAULT NULL,
  `personnel` int(5) DEFAULT NULL,
  `rd_name` varchar(15) COLLATE utf8_persian_ci DEFAULT NULL,
  `rd_tel` varchar(11) COLLATE utf8_persian_ci DEFAULT NULL,
  `priority` enum('الف','ب','غیره') COLLATE utf8_persian_ci DEFAULT NULL,
  `electric` varchar(11) COLLATE utf8_persian_ci DEFAULT NULL,
  `water` varchar(11) COLLATE utf8_persian_ci DEFAULT NULL,
  `energy` varchar(11) COLLATE utf8_persian_ci DEFAULT NULL,
  `energy_type` enum('گاز','گازوئیل','نفت و گاز') COLLATE utf8_persian_ci DEFAULT NULL,
  `activity_id` int(6) DEFAULT NULL,
  `about` varchar(300) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`user_id`),
  UNIQUE KEY `code` (`code`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `companies`
--

LOCK TABLES `companies` WRITE;
/*!40000 ALTER TABLE `companies` DISABLE KEYS */;
INSERT INTO `companies` VALUES (62,123,'2014/01/08','ایران','قم','اداری',123,'456',50,'محمدی','4560912','الف','2','3','4','نفت و گاز',2,'درباره شرکت من'),(71,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(78,329,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(79,1359,NULL,'ایران','مازندران آمل شهرک صنعتی بابکان شرکت صنعتی خزر الکتریک','تجهیزات صنعتی و تبدیلی کشاورزی  ',NULL,NULL,150,'مهندس محمد ذبیح','01213113941',NULL,NULL,NULL,NULL,NULL,10,' خزرالکتریک تولید کننده سیستم تهویه مطبوع و خشک کن صنعتی   شرکت خزر الکتریک تولیدکننده انواع هواکش های صنعتی، سیستم تهویه مطبوع، سیستم پخت ضایعات پروتئینی، خشک کن صنعتی، شات بلاست، دستگاه استریل و بازیافت ضایعات و غیره می باشد. این واحد تولیدی، در سال 1359 فعالیت تولیدی خود را با اتکا به خلاقیت و اب'),(81,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(82,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(85,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(91,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
/*!40000 ALTER TABLE `companies` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `group_members`
--

DROP TABLE IF EXISTS `group_members`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `group_members` (
  `id` int(6) NOT NULL AUTO_INCREMENT,
  `group_id` int(6) DEFAULT NULL,
  `user_id` int(6) DEFAULT NULL,
  `type` enum('admin','member') COLLATE utf8_persian_ci DEFAULT 'member',
  `status` enum('awaiting','active','dismissal','quit','reject') COLLATE utf8_persian_ci DEFAULT 'awaiting',
  `date` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  `exit_date` date DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=44 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `group_members`
--

LOCK TABLES `group_members` WRITE;
/*!40000 ALTER TABLE `group_members` DISABLE KEYS */;
INSERT INTO `group_members` VALUES (9,12,51,'admin','active','2014-01-26 02:01:55',NULL),(39,12,63,'member','reject','2014-01-27 03:04:23',NULL),(41,17,51,'admin','active','2014-01-30 00:56:51',NULL),(43,12,72,'member','awaiting','2014-02-19 13:21:00',NULL);
/*!40000 ALTER TABLE `group_members` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `groups`
--

DROP TABLE IF EXISTS `groups`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `groups` (
  `group_id` int(6) NOT NULL AUTO_INCREMENT,
  `title` varchar(50) COLLATE utf8_persian_ci DEFAULT NULL,
  `content` text COLLATE utf8_persian_ci,
  `admin_id` int(6) DEFAULT NULL,
  `date` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  `activity_id` int(6) DEFAULT NULL,
  PRIMARY KEY (`group_id`)
) ENGINE=InnoDB AUTO_INCREMENT=18 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `groups`
--

LOCK TABLES `groups` WRITE;
/*!40000 ALTER TABLE `groups` DISABLE KEYS */;
INSERT INTO `groups` VALUES (12,'تیم میکسا','تیم طراح وب',51,'2014-01-26 02:01:01',2),(17,'پژوهشگران آینده','',51,'2014-01-30 00:56:51',2);
/*!40000 ALTER TABLE `groups` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'NO_AUTO_VALUE_ON_ZERO' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`rprb`@`localhost`*/ /*!50003 TRIGGER `rprb`.`groups_on_insert_add_in_member` AFTER INSERT ON `rprb`.`groups` FOR EACH ROW BEGIN    
 INSERT INTO group_members 
    (group_id, user_id, type, status) 
    VALUES(NEW.group_id, NEW.admin_id, 'admin', 'active');
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `m_file_folder`
--

DROP TABLE IF EXISTS `m_file_folder`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `m_file_folder` (
  `id` int(6) NOT NULL,
  `name` varchar(15) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `m_file_folder`
--

LOCK TABLES `m_file_folder` WRITE;
/*!40000 ALTER TABLE `m_file_folder` DISABLE KEYS */;
/*!40000 ALTER TABLE `m_file_folder` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `m_files`
--

DROP TABLE IF EXISTS `m_files`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `m_files` (
  `id` int(6) NOT NULL AUTO_INCREMENT,
  `title` varchar(15) COLLATE utf8_persian_ci DEFAULT NULL,
  `model` enum('proposal','finalresult','admin','profile') COLLATE utf8_persian_ci DEFAULT 'proposal',
  `addr_id` int(6) DEFAULT NULL,
  `filename` int(11) DEFAULT NULL,
  `type` varchar(50) COLLATE utf8_persian_ci DEFAULT NULL,
  `size` float DEFAULT NULL,
  `description` varchar(50) COLLATE utf8_persian_ci DEFAULT NULL,
  `user_id` int(6) DEFAULT NULL,
  `time` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=27 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `m_files`
--

LOCK TABLES `m_files` WRITE;
/*!40000 ALTER TABLE `m_files` DISABLE KEYS */;
INSERT INTO `m_files` VALUES (1,NULL,'proposal',151301,NULL,'doc',74240,NULL,51,'2014-02-01 12:26:36'),(2,NULL,'proposal',151301,NULL,'pdf',222580,NULL,51,'2014-02-01 12:28:51'),(3,NULL,'proposal',151301,NULL,'pdf',526936,NULL,51,'2014-02-01 12:29:46'),(4,NULL,'proposal',151301,NULL,'docx',37567,NULL,51,'2014-02-01 12:30:57'),(5,NULL,'proposal',151301,NULL,'pdf',67891,NULL,51,'2014-02-01 12:32:42'),(6,NULL,'proposal',151301,NULL,'pdf',222580,NULL,51,'2014-02-01 12:45:38'),(7,NULL,'proposal',151301,NULL,'pdf',222580,NULL,51,'2014-02-01 12:51:24'),(8,NULL,'proposal',151301,NULL,'docx',13209,NULL,51,'2014-02-03 18:49:45'),(9,NULL,'proposal',151301,NULL,'docx',14072,NULL,67,'2014-02-16 23:16:57'),(10,NULL,'proposal',151301,NULL,'doc',241579,NULL,67,'2014-02-16 23:17:25'),(11,NULL,'proposal',151301,NULL,'docx',14237,NULL,67,'2014-02-16 23:23:14'),(12,'کارت ملی','profile',151301,151313,'gif',5869,'test1',51,'2014-03-04 23:29:54'),(13,'researcher','proposal',151301,151314,'docx',37772,'این یک تست است',51,'2014-03-06 10:19:17'),(14,'researcher','proposal',151301,151315,'docx',37772,'تست نهایی تست نهایی تست ن',51,'2014-03-06 10:20:14'),(15,'researcher','proposal',151301,151316,'docx',37772,'تست نهایی تست نهایی تست ن',51,'2014-03-06 10:20:51'),(17,'researcher','proposal',151301,151318,'docx',37772,'تست نهایی تست نهایی تست ن',51,'2014-03-06 10:21:40'),(18,'researcher','proposal',151301,151319,'docx',13209,'ی ثبت شده برای پژوهش را د',62,'2014-03-06 16:38:04'),(19,'کارت ملی','profile',151301,151320,'jpg',20688,'',77,'2014-03-08 06:46:00'),(20,'شناسنامه','profile',151301,151321,'jpg',3092630,'',77,'2014-03-08 06:47:13'),(21,'شناسنامه','profile',151301,151322,'jpg',3092630,'',77,'2014-03-08 06:48:39'),(22,'مدرک تحصیلی','profile',151301,151323,'jpg',24523,'',77,'2014-03-08 06:51:25'),(23,'گواهی عضو هیئت ','profile',151301,151324,'jpg',23255,'',77,'2014-03-08 06:51:41'),(24,'کارت ملی','profile',151301,151325,'jpg',82856,'',83,'2014-04-29 12:33:26'),(25,'شناسنامه','profile',151301,151326,'jpg',265274,'',83,'2014-04-29 12:33:59'),(26,'مدرک تحصیلی','profile',151301,151327,'jpg',377435,'',83,'2014-04-29 12:34:51');
/*!40000 ALTER TABLE `m_files` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'NO_AUTO_VALUE_ON_ZERO' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`rprb`@`localhost`*/ /*!50003 TRIGGER `rprb`.`files_on_insert_create_file_name` BEFORE INSERT ON `rprb`.`m_files` FOR EACH ROW BEGIN
DECLARE next_id INT;
SET next_id = (SELECT AUTO_INCREMENT FROM information_schema.TABLES WHERE TABLE_SCHEMA=DATABASE() AND TABLE_NAME='m_files');
SET NEW.filename = next_id + 151301;
SET NEW.addr_id = FLOOR( next_id /1000 ) +151301;
End */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `m_options`
--

DROP TABLE IF EXISTS `m_options`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `m_options` (
  `option_id` int(11) NOT NULL AUTO_INCREMENT,
  `option_cat` varchar(30) COLLATE utf8_persian_ci DEFAULT NULL,
  `option_name` varchar(100) COLLATE utf8_persian_ci NOT NULL,
  `option_value` text COLLATE utf8_persian_ci NOT NULL,
  `option_status` enum('on','off') COLLATE utf8_persian_ci NOT NULL DEFAULT 'on',
  PRIMARY KEY (`option_id`)
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `m_options`
--

LOCK TABLES `m_options` WRITE;
/*!40000 ALTER TABLE `m_options` DISABLE KEYS */;
INSERT INTO `m_options` VALUES (1,'page_title','home/home/','سامانه پژوهش های تقاضا محور','on'),(2,'general','site_title','سامانه پژوهش های تقاضا محور','on'),(3,'general','site_desc','آشنایی مراکز دانشگاهی و پژوهشگران با اولویت های پژوهشی بنگاه‌های اقتصادی همواره یکی از چالش‌های اساسی ارتباط بنگاه اقتصادی با پژوهشگران در کشور می‌باشد.','on'),(4,'page_title','u/home/','مشخصات کاربری','on'),(5,'page_title','u/edit/','ویرایش مشخصات کاربری','on'),(6,'page_title','user/home/','صفحه اصلی کاربران','on'),(7,'page_title','user/login/','ورود کاربران','on'),(8,'page_title','user/forgotten/','بازیابی کلمه عبور','on'),(9,'page_title','user/register/','ثبت نام کاربر جدید','on'),(10,'page_title','admin/home/','پنل مدیریت','on'),(11,'page_title','profile/researcher/','نمایش پروفایل پژوهشگران','on'),(12,'page_title','profile/home/','پروفایل','on'),(13,'page_title','research/add/','افزودن پژوهش جدید','on'),(14,'research','contract_text','طرف اول قرارداد ( كار فرما ) : نام و نام خانوادگي و مشخصات شناسنامه و نشاني كامل براي اشخاص حقيقي و نام شركت يا موسسه ، نوع آن و شماره ثبت و نشاني قانوني دفتر مركزي آن براي اشخاص حقوقي در اين قسمت بايد درج گردد .\n\nطرف دوم قرارداد ( پيمانكار ) : نام و مشخصات كامل و نشاني پيمانكار ( كسي كه انجام نوعي كارهاي خدماتي را بر طبق خواسته كار فرما قبول نموده ) اعم از آنكه شخص حقيقي يا حقوقي باشد در اين قسمت بايد درج گردد .\nموضوع قرارداد : موضوع قرارداد به صورت کامل و واضح در این قسمت نوشته می شود .\n\nمدت قرارداد : مدتی که بر روی آن توافق شده است در این قسمت نوشته می شود .\n\nمبلغ قرارداد : مبلغ قرارداد به صورت کلی و یا هر مرحله از انجام کار و نحوه ی پرداخت ان در این قسمت نوشته می شود .\n\nشرايط : سایر شرایطی که بر روی آن توافق نموده اید مانند بیمه ، مالیات ، عوارض و سپرده حسن انجام کار و شرایط تحویل کار و آزاد سازی سپرده در این قسمت نوشته می شود .\n\nفرس ماژور : شرايط فورس ماژور در اين قسمت درج مي گردد .\n\nحل اختلاف : تمامي موارد احتمالي كه باعث حل اختلاف شود و در اينصورت نحوه حل آن از طريق مراجعه به داور مورد قبول طرفين و يا مراجع صالحه قضائي در اين قسمت درج مي گردد .\n\nتعداد نسخ و اعتبار قرارداد : اين قرارداد در ………… نسخه و هر نسخه در ……… صفحه كه تماما\" داراي اعتبار واحد است تنظيم گرديده و طرفين قرارداد با آگاهي و اطلاع كامل از مفاد ماده 10 قانون مدني جمهوري اسلامي ايران ، آنرا با امضاء خود مورد تأئيد و قبول قرار داده اند .\n\nضمائم قرارداد : ……………………………………….…….………………………\n این یک متن نمونه است','on'),(15,'page_title','research/home/','لیست تقاضاهای پژوهشی ثبت شده','on'),(16,'page_title','group/home/','لیست گروه های پژوهشی تشکیل شده','on');
/*!40000 ALTER TABLE `m_options` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `m_posts`
--

DROP TABLE IF EXISTS `m_posts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `m_posts` (
  `post_id` int(20) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(6) NOT NULL,
  `publish_date` datetime NOT NULL,
  `title` text COLLATE utf8_persian_ci NOT NULL,
  `content` text COLLATE utf8_persian_ci NOT NULL,
  `slug` varchar(200) COLLATE utf8_persian_ci NOT NULL,
  `slug_cat` varchar(200) COLLATE utf8_persian_ci DEFAULT NULL,
  `type` enum('post','page') COLLATE utf8_persian_ci NOT NULL,
  `status` enum('publish','draft') COLLATE utf8_persian_ci NOT NULL DEFAULT 'publish',
  `changetime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`post_id`),
  UNIQUE KEY `slug` (`slug`)
) ENGINE=InnoDB AUTO_INCREMENT=23 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `m_posts`
--

LOCK TABLES `m_posts` WRITE;
/*!40000 ALTER TABLE `m_posts` DISABLE KEYS */;
INSERT INTO `m_posts` VALUES (2,68,'2014-03-10 14:05:17','شروع دوره آزمایشی سامانه دوم','با احترام، به اطلاع میرساند دوره آزمایشی سامانه شروع شد.','news22','news','post','draft','2014-03-10 10:35:17'),(3,68,'2014-03-10 14:05:15','سامانه راه اندازی شد','&lt;p style=&quot;text-align:right;&quot;&gt;راه اندازی اولیه &lt;strong&gt;سامانه&lt;/strong&gt; به انجام رسید&lt;/p&gt;','news1','news','post','publish','2014-03-10 10:35:15'),(5,51,'2014-02-04 01:26:47','سامانه پژوهش های تقاضا محور به چه معناست؟','هدف از راه اندازی سامانه تحت وب پژوهشهای تقاضا محور ارتباط مستقیم بین متخصصین دانشگاهی، صنایع کشور و بنگا&not;های اقتصادی است.\r<br/> حفظ منابع مالی در بخش خصوصی از طریق کمک به ارتقا بهره وری و کاهش وابستگی پروژه های پژوهشی به بودجه دولتی از اهداف دیگر این طرح می باشد. در این سامانه بنگاه&not;های اقتصادی، نهادها و سازمانهای دولتی و خصوصی در فضاهای دسته بندی شده ضمن معرفی مجموعه خود، اقدام به طرح مساله در حوزه&not;های گوناگون فضای کسب&not;وکار از چالشهای سازمانی مانند مهندسی فاکتورهای انسانی، مهندسی مالی تا  مهندسی نگهداری و تعمیرات پیشبینانه&not;و پیشگیرانه می&not;نمایند. در طرف مقابل محققین و اساتید داشگاهی نیز ضمن رصد موارد فوق اقدام به معرفی طرحهای پژوهشی خود  به منظور برخورداری از حمایتهای مالی بخش خصوصی، در سه سطح آزمایشگاهی، نیمه&not;صنعتی و صنعتی نموده و دستاوردهای خود را مستقیما به بازار هدف معرفی می&not;نمایند.\r<br/>سامانه پژوهشهای تقاضا محور، یک دایره المعارف پژوهشی برای کلیه رشته های علوم است که هدف از راه اندازی آن، ایجاد بستری مناسب جهت ارائه اولویتهای پژوهشی وآشنایی بیشتر بنگاه های اقتصادی با پژوهشگران و بالعکس می باشد.\r<br/>البته یکی از بزرگترین دستاوردهای این پایگاه در از بین بردن مرزهای جغرافیایی و فواصل برای دسترسی به اولویتهای پژوهشی سازمانها و نهادهای غیردولتی میباشد \r<br/>','what',NULL,'page','publish','2014-02-03 21:56:47'),(6,51,'2014-02-04 00:59:01','تماس با ما','برای تماس با ما می توانید به Info@RpRb.ir ایمیل بزنید.','contact',NULL,'page','publish','2014-02-03 21:29:01'),(10,51,'2014-02-04 01:12:53','سوالات متداول','&bull;	هدف اصلی این سامانه چیست؟ <br/>هدف از راه اندازی سامانه تحت وب پژوهشهای تقاضا محور  تبدیل چالش و مسئله به اولویت پژوهشی، سپس اجرای طرح پژوهشی و ارائه راه&not;کارهای حل مسئله و در نهایت تولید ثروت از اجرای طرح&not;های پژوهشی است. <br/><br/>&bull;	این سامانه برای چه اشخاص یا گروه هایی تهیه شده است؟<br/>بنگاه&not;&not;های اقتصادی، سازمان&not;ها، صنایع، نهادهای دولتی و غیر دولتی از یک سو به عنوان کارفرما و  دانشگاه&not;ها ، موسسات پژوهشی از سوی دیگر است.<br/>&bull;	چه پژوهش&zwnj;هایی توسط این سامانه قابل انجام است؟<br/>برمبنای نیاز متقاضیان دریافت خدمات پژوهشی، هیچ محدودیتی در عنوان و نوع پژوهش برابر مقررات جاری کشور وجود ندارد.<br/>&bull;	استفاده از این سامانه چه مزیتی برای پژوهشگران دارد؟<br/>مشاهده نیازهای پژوهشی و اولویت&not;های پژوهشی بنگاه&not;های اقتصادی، ارائه توانمندی&not;های پژوهشگران، تشکیل شبکه علمی پژوهشگران، دسترسی به بانک اطلاعاتی پژوهش&not;های سفارشی و کاربردی<br/>&bull;	آیا این سامانه کیفیت و امنیت پژوهش ها را تضمین می کند؟<br/>این سامانه توسط ارائه راهکارهای نوین نظارتی، کیفیت پژوهش و امنیت اطلاعات آن را برای صاحبان بنگاه&not;ها و همچنین پژوهشگران تضمین می&not;نماید<br/>&bull;	روند کار سامانه چگونه است<br/>مرحله اول: تبدیل چالش و یا مسئله مطرح شده توسط بنگاه اقتصادی به طرح پژوهشی، سپس اولویت بندی طرح&not;ها و معرفی طرح به پژوهشگران عضو سامانه. <br/>مرحله دوم: دریافت پیشنهادات تحقیق از سوی دانشگاه&not;ها و موسسات پژوهشی، داوری و انتخاب چند طرح پژوهشی مرتبط و معرفی آن به کارفرما<br/>مرحله سوم: عقد قرارداد بین پژوهشگر و کارفرما <br/>مرحله چهارم: نظارت بر شیوه اجرا مفاد قرارداد و راستی&not;آزمایی نتایج و ارائه به کارفرما<br/> <br/>&bull;	این سامانه چه کمکی به پژوهشگران کشور می کند؟<br/>مشاهده نیازهای پژوهشی و اولویت&not;های پژوهشی بنگاه&not;های اقتصادی، ارائه توانمندی&not;های پژوهشگران، تشکیل شبکه علمی پژوهشگران، دسترسی به بانک اطلاعاتی پژوهش&not;های سفارشی و کاربردی<br/>&bull;	این سامانه چه کمکی به شرکت ها و صنعتگران کشور می کند؟<br/>تبدیل مسائل و چالشهای موجود به طرح پژوهشی، بنگاه&not;های اقتصادی، نهادها و سازمانهای دولتی و خصوصی در فضاهای دسته بندی شده ضمن معرفی مجموعه خود، اقدام به طرح مساله در حوزه&not;های گوناگون فضای کسب&not;وکار خود  می&not;نمایند. همچنین به بانک اطلاعاتی پژوهشگران و یافته&not;های جدید پژوهشی دسترسی می&not;یابد.  <br/>&bull;	مزیت این سامانه برای پژوهشگران؟سئوال تکراری است<br/>&bull;	مزیت این سامانه برای شرکت ها؟ سئوال تکراری است<br/>&bull;	مزیت این سامانه برای کشور؟ سئوال حذف شود<br/>&bull;	هزینه راه اندازی و پشتیبانی این سامانه از کجا تامین می شود؟<br/>هزینه راه&not;اندازی سامانه از محل کمک&not;های معاونت محترم پژوهشی وزارت علوم، تحقیقات و فن-آوری تامین گردیده است. در مراحل بعدی از محل درآمدهای حاصل از هزینه بالاسری اجرای پروژه ها تامین خواهد شد.<br/>','faq',NULL,'page','publish','2014-02-03 21:42:53'),(11,51,'2014-02-04 01:16:23','شرایط و قوانین','\r<br/>1.	سامانه می تواند اطلاعات مختلف پژوهشگران و بنگاه ها را در قالب فایل های اطلاعاتی با سایرین به اشتراک بگذارد . \r<br/>2.	سامانه  نظرات سایرین را در رابطه با موضوعات سازمانی مختلف از طریق این سایت دریافت نمایید . \r<br/>3.	آدرس ایمیل شما توسط  اعضا قابل دیدن خواهد بود.\r<br/>4.	اولویت&not;های پژوهشی سازمانها توسط کاربران قابل رویت می&not;باشد مگر مواردی را که به صورت مکتوب تقاضا شود.\r<br/>5.	کاربر متعهد می شود که از روی عمد اطلاعات غلط و یا اطلاعاتی که منجر به گمراهی دیگران شود را ثبت نکند.\r<br/>6.	کاربر نباید مطالبی را ثبت کند که مخالف با موازین و قوانین جمهوری اسلامی ایران می باشد. کاربر نباید اطلاعات محرمانه ، طبقه بندی شده و حساس را ارائه نمایید .\r<br/>7.	کاربر نباید مواردی را ثبت، پخش یا ثبت دوباره کند که مالکیت معنوی آن متعلق به دیگران می باشد و یا ثبت مارک تجاری شده اند.','terms',NULL,'page','publish','2014-02-03 21:46:23'),(13,51,'2014-02-04 01:20:44','حریم خصوصی','اطلاعاتی که بنا به درخواست ما یا به تناسب نیاز در سایت درج می&zwnj;شود، محرمانه تلقی نمی گردد. مگر در مواردی که بنگاه اقتصادی و یا پژوهشگر تقاضای معین و مکتوبی را ارائه نمایند. روشن است که تعهد ما در چهار&zwnj;چوب قانون و مبتنی بر شرایط عادی است. \r<br/>اطلاعات مربوط به پست الکترونیکی کاربر، فقط برای ارسال اطلاعات و تماس با وی از سوی کاربران عضو سامانه  موردبهره&zwnj;برداری قرار می&zwnj;گیرد. \r<br/>در صورت درخواست کاربر، امکان حذف نشانی پست الکترونیکی از فهرست&zwnj;های سامانه وجود دارد.\r<br/>مسؤلیت درستی مطالبی که کاربران ارسال می&zwnj;کنند یا به صورت مستقیم در سایت درج می&zwnj;کنند، به عهدهء نویسندگان آنهاست.\r<br/>سامانه در ویرایش و اصلاح هر نوع مطلب، مقاله و نوشتهء فرستاده شده، آزاد است.\r<br/>اطلاعات مربوط به کیفیت کاربران شامل: نوع مرورگر،IP و زمان تماس برای تهیهء گزارش و تحلیل مورداستفاده قرار می&zwnj;گیرد.\r<br/>استفاده از اطلاعات متنی پایگاه&zwnj;وب با رعایت حق مؤلف و عدم انتشار متن کامل اطلاعات (به شکل چاپی یا الکترونیکی) کاملا آزاد و رایگان است. \r<br/>\r<br/>انتشار متن کامل اطلاعات (چاپی یا الکترونیکی) بدون کسب مجوز مجاز نیست و حق هرگونه اقدام قانونی برای سامانه محفوظ است.\r<br/>شرط استفاده (با شرایط یادشده) از اطلاعات متنی سایت، ذکر نام نویسنده/مترجم و نشانی دقیق اینترنتی مطلب مورداستفاده، است.\r<br/> \r<br/>نقل چکیده یا خلاصهء مطالب درج&zwnj;شده در سایت در دیگر محیط&zwnj;های الکترونیکی (مانند سایت&zwnj;های اینترنتی) باید همراه با درج نشانی پیوند (لینک) اینترنتی سامانه باشد.\r<br/> \r<br/>انتشار (چاپی یا الکترونیکی) مقاله&zwnj;ها، کتاب&zwnj;ها، گزارش طرح&zwnj;های پژوهشی، گزارش&zwnj;های علمی و مقاله&zwnj;های همایش&zwnj;ها بدون اخذ مجوز از سامانه ممنوع است. \r<br/> نقل مطالب با ذکر منبع کاملاً آزاد است.\r<br/> \r<br/>انتشار متن کامل &zwnj;مطالب نیازمند کسب &zwnj;اجازه &zwnj;است. ','privacy',NULL,'page','publish','2014-02-03 21:50:44'),(14,51,'2014-02-04 01:23:04','این سامانه چگونه کار می کند؟','مرحله اول: تبدیل چالش و یا مسئله مطرح شده توسط بنگاه اقتصادی به طرح پژوهشی، سپس اولویت بندی طرح&not;ها و معرفی طرح به پژوهشگران عضو سامانه. \r<br/>مرحله دوم: دریافت پیشنهادات تحقیق از سوی دانشگاه&not;ها و موسسات پژوهشی، داوری و انتخاب چند طرح پژوهشی مرتبط و معرفی آن به کارفرما\r<br/>مرحله سوم: عقد قرارداد بین پژوهشگر و کارفرما \r<br/>مرحله چهارم: نظارت بر شیوه اجرا مفاد قرارداد و راستی&not;آزمایی نتایج و ارائه به کارفرما\r<br/>','how',NULL,'page','publish','2014-02-03 21:53:04'),(15,67,'2014-02-17 10:45:45','این سامانه برای چه کسانی است؟','بنگاه&not;&not;های اقتصادی، سازمان&not;ها، صنایع، نهادهای دولتی و غیر دولتی از یک سو به عنوان کارفرما و  دانشگاه&not;ها ، موسسات پژوهشی از سوی دیگر است.','who',NULL,'page','publish','2014-02-17 07:15:45'),(16,51,'2014-02-04 01:27:47','درباره','هدف از راه اندازی سامانه تحت وب پژوهشهای تقاضا محور ارتباط مستقیم بین متخصصین دانشگاهی، صنایع کشور و بنگا&not;های اقتصادی است.\r<br/> حفظ منابع مالی در بخش خصوصی از طریق کمک به ارتقا بهره وری و کاهش وابستگی پروژه های پژوهشی به بودجه دولتی از اهداف دیگر این طرح می باشد. در این سامانه بنگاه&not;های اقتصادی، نهادها و سازمانهای دولتی و خصوصی در فضاهای دسته بندی شده ضمن معرفی مجموعه خود، اقدام به طرح مساله در حوزه&not;های گوناگون فضای کسب&not;وکار از چالشهای سازمانی مانند مهندسی فاکتورهای انسانی، مهندسی مالی تا  مهندسی نگهداری و تعمیرات پیشبینانه&not;و پیشگیرانه می&not;نمایند. در طرف مقابل محققین و اساتید داشگاهی نیز ضمن رصد موارد فوق اقدام به معرفی طرحهای پژوهشی خود  به منظور برخورداری از حمایتهای مالی بخش خصوصی، در سه سطح آزمایشگاهی، نیمه&not;صنعتی و صنعتی نموده و دستاوردهای خود را مستقیما به بازار هدف معرفی می&not;نمایند.\r<br/>سامانه پژوهشهای تقاضا محور، یک دایره المعارف پژوهشی برای کلیه رشته های علوم است که هدف از راه اندازی آن، ایجاد بستری مناسب جهت ارائه اولویتهای پژوهشی وآشنایی بیشتر بنگاه های اقتصادی با پژوهشگران و بالعکس می باشد.\r<br/>البته یکی از بزرگترین دستاوردهای این پایگاه در از بین بردن مرزهای جغرافیایی و فواصل برای دسترسی به اولویتهای پژوهشی سازمانها و نهادهای غیردولتی میباشد \r<br/>','about',NULL,'page','publish','2014-02-03 21:57:47'),(17,68,'2014-03-10 14:05:32','مقاله مطالعات هیدرولیک زیست محیطی عضو هیأت علمی دانشگاه صنعتی اصفهان پراستنادترین مقاله مجله بین المللی','براساس گزارش اخیرسایت اسکوپوس، مقاله دکتر حسین افضلی مهرعضو هیأت علمی دانشگاه صنعتی اصفهان، عنوان پر استنادترین مقاله مجله بین المللی International Journal of Sediment Research را به خود اختصاص داد.','مقاله_مطالعات_هیدرولیک','news','post','publish','2014-03-10 10:35:32'),(18,68,'2014-03-10 14:05:40','تدوین دانش فنی ساخت نانوکامپوزیت آلومینا-مولایت در پژوهشگاه مواد و انرژی','پژوهشگاه مواد و انرژی به دانش فنی ساخت نانوکامپوزیت آلومینا-مولایت در پژوهشگاه مواد و انرژی دست پیدا کرد.','تدوین_دانش_فنی_ساخت_نانوکامپوزیت','news','post','publish','2014-03-10 10:35:40'),(19,68,'2014-02-19 15:18:20','تفاهم نامه همکاری پژوهشگاه مواد وانرژی با دانشگاه خوارزمی منعقد شد','تفاهم نامه همکاری به منظور ایجاد زمینه مناسب جهت انجام همکاری های متقابل مابین پژوهشگاه مواد وانرژی و دانشگاه خوارزمی منعقد شد.','تفاهم_نامه_همکاری_پژوهشگاه_مواد_وانرژی_با_دانشگاه_خوارزمی_منعقد_شد','news','post','publish','2014-03-02 22:57:06'),(20,68,'2014-03-10 14:04:44','چگونه فناوری نانو به توسعه دانش پزشکی کمک نموده است؟','&lt;p&gt;&lt;span style=&quot;color:#424242;font-family:nassim, tahoma;font-size:16px;line-height:22.399999618530273px;background-color:#FFFFFF;&quot;&gt;همزمان با برگزاری پنجمین جشنواره فناوری نانو از 7 محصول نوین در حوزه فناوری نانو رونمایی گردید. یکی از محصولات رونمایی شده، دستگاه &quot;برش&zwnj;نگاری فلورسنت مولکولی&quot; بود که توسط شرکت&quot; تجهیز آفرینان نوری پارسه&quot; طراحی و ساخته شده است. این شرکت در سال 1390 با هدف ساخت تجهیزات تصویربرداری اپتیکی از حیوان کوچک ایجاد گردید.&lt;/span&gt;&lt;/p&gt;&lt;p&gt;&lt;span style=&quot;color:#424242;font-family:nassim, tahoma;font-size:16px;line-height:22.399999618530273px;background-color:#FFFFFF;&quot;&gt;&lt;span style=&quot;color:#424242;font-family:nassim, tahoma;font-size:16px;line-height:22.399999618530273px;background-color:#FFFFFF;&quot;&gt;این مقاله در نشریه&nbsp;&lt;/span&gt;&lt;a href=&quot;http://www.nano.ir/index.php?ctrl=publisher&amp;actn=publisher_number&amp;id=1316&amp;lang=1&quot; data-ke-src=&quot;http://www.nano.ir/index.php?ctrl=publisher&amp;actn=publisher_number&amp;id=1316&amp;lang=1&quot;&gt;فناوری نانو شماره 195&lt;/a&gt;&lt;span style=&quot;color:#424242;font-family:nassim, tahoma;font-size:16px;line-height:22.399999618530273px;background-color:#FFFFFF;&quot;&gt;&nbsp;در تاریخ 1392/10/15 به چاپ رسیده است.&lt;/span&gt;​&lt;br&gt;&lt;/span&gt;&lt;/p&gt;','چگونه_فناوری_نانو_به_توسعه_دانش_پزشکی_کمک_نموده_است؟','article','post','publish','2014-03-10 10:34:44'),(21,68,'2014-03-07 15:08:26','مجله قانون و تجارت فناوری نانو، شماره 9.4','&amp;amp;lt;p&amp;amp;gt;\n	salam\n&amp;amp;lt;/p&amp;amp;gt;\n&amp;amp;lt;p&amp;amp;gt;\n	&amp;amp;lt;br /&amp;amp;gt;\n&amp;amp;lt;/p&amp;amp;gt;','مجله_قانون_و_تجارت_فناوری_نانو،_شماره_9.4','article','post','publish','2014-03-07 11:38:26'),(22,68,'2014-03-10 14:03:51','فناوری نانو در کره جنوبی','&lt;p&gt;\n	رصد فناوری نانو در کشورهای مختلف می&zwnj;تواند اطاعات مناسبی برای مدیران و تصمیم&zwnj;سازان عرصه فناوری نانو باشد. در این گزارش وضعیت کره جنوبی در فناوری نانو از سال 2000 تا کنون مورد بررسی قرار گرفت. ابتدا روند وارد شدن این کشور به عرصه فناوری نانو ارائه شده و در ادامه برنامه&zwnj;ها، بودجه&zwnj;ها، مراکز تحقیقاتی و دستاوردهای این کشور ارائه می&zwnj;شود. در قسمتی از گزارش آمار مقالات، ارجاعات و پتنت&zwnj;های این کشور مورد بررسی قرار می&zwnj;گیرد.\n&lt;/p&gt;\n&lt;p&gt;\n	این مقاله در نشریه فناوری نانو شماره 194 در تاریخ 1392/09/15 به چاپ رسیده است.\n&lt;/p&gt;\n&lt;p&gt;\n	&lt;a href=&quot;http://irannano.org/filereader.php?p1=main_1679091c5a880faf6fb5e6087eb1b2dc573.pdf&amp;amp;p2=paper&amp;amp;p3=1&amp;amp;p4=1&quot; target=&quot;_blank&quot;&gt;دانلود مقاله&lt;/a&gt;&lt;span&gt;&lt;/span&gt;\n&lt;/p&gt;','فناوری_نانو_در_کره_جنوبی','article','post','publish','2014-03-10 10:33:51');
/*!40000 ALTER TABLE `m_posts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `m_term_usage`
--

DROP TABLE IF EXISTS `m_term_usage`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `m_term_usage` (
  `term_usage_id` bigint(20) NOT NULL AUTO_INCREMENT,
  `term_id` int(20) unsigned NOT NULL,
  `post_id` int(20) unsigned NOT NULL,
  PRIMARY KEY (`term_usage_id`)
) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `m_term_usage`
--

LOCK TABLES `m_term_usage` WRITE;
/*!40000 ALTER TABLE `m_term_usage` DISABLE KEYS */;
INSERT INTO `m_term_usage` VALUES (1,1,2),(2,1,3),(3,2,7),(4,1,8),(5,1,9),(6,1,10),(7,1,11),(8,1,5),(9,1,6),(10,1,10),(11,1,11),(12,1,13),(13,1,14),(14,1,15),(15,1,16),(16,1,17),(17,1,18),(18,1,19),(19,4,20),(20,4,21),(21,4,22);
/*!40000 ALTER TABLE `m_term_usage` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `m_terms`
--

DROP TABLE IF EXISTS `m_terms`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `m_terms` (
  `term_id` int(20) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(200) COLLATE utf8_persian_ci NOT NULL,
  `slug` varchar(200) COLLATE utf8_persian_ci NOT NULL,
  `desc` varchar(200) COLLATE utf8_persian_ci NOT NULL,
  `type` enum('cat','tag') COLLATE utf8_persian_ci NOT NULL DEFAULT 'cat',
  PRIMARY KEY (`term_id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `m_terms`
--

LOCK TABLES `m_terms` WRITE;
/*!40000 ALTER TABLE `m_terms` DISABLE KEYS */;
INSERT INTO `m_terms` VALUES (1,'اخبار اصلی','news','این توضیح دسته اول است','cat'),(2,'رویداد','events','این توضیح دسته دوم است','cat'),(3,'تگ اول','tag1','این برای تگ اول است','tag'),(4,'مقالات','article','مقالات علمی منتشر شده در سامانه','cat');
/*!40000 ALTER TABLE `m_terms` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `m_users`
--

DROP TABLE IF EXISTS `m_users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `m_users` (
  `user_id` int(6) NOT NULL AUTO_INCREMENT,
  `username` varchar(50) COLLATE utf8_persian_ci NOT NULL,
  `password` char(64) COLLATE utf8_persian_ci NOT NULL,
  `email` varchar(50) COLLATE utf8_persian_ci NOT NULL,
  `type` enum('admin','researcher','company','overseer') COLLATE utf8_persian_ci NOT NULL DEFAULT 'researcher',
  `mode` enum('حقیقی','حقوقی') COLLATE utf8_persian_ci DEFAULT 'حقیقی',
  `firstname` varchar(30) COLLATE utf8_persian_ci NOT NULL,
  `lastname` varchar(50) COLLATE utf8_persian_ci NOT NULL,
  `tel` varchar(11) COLLATE utf8_persian_ci NOT NULL,
  `website` varchar(30) COLLATE utf8_persian_ci NOT NULL,
  `status` enum('active','awaiting','deactive','removed') COLLATE utf8_persian_ci NOT NULL DEFAULT 'active',
  PRIMARY KEY (`user_id`),
  UNIQUE KEY `username` (`username`,`email`,`tel`,`website`)
) ENGINE=InnoDB AUTO_INCREMENT=338 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `m_users`
--

LOCK TABLES `m_users` WRITE;
/*!40000 ALTER TABLE `m_users` DISABLE KEYS */;
INSERT INTO `m_users` VALUES (51,'J.Evazzadeh@gmail.com','96e79218965eb72c92a549dd5a330112','J.Evazzadeh@gmail.com','researcher','حقیقی','جواد','عوض زاده','3236','evazzadeh.com','active'),(62,'javadreg@gmail.com','96e79218965eb72c92a549dd5a330112','javadreg@gmail.com','company','حقیقی','شرکت','میکسا','1230912','mixa.ir','active'),(68,'info@rprb.ir','4154753409859dd41ceff19190946a5c','info@rprb.ir','admin',NULL,'مدیریت','سایت','','rprb.ir','active'),(71,'test6@test.com','96e79218965eb72c92a549dd5a330112','test6@test.com','company','حقیقی','موسسه','نانوکار پارس','','','active'),(76,'majidpeyravi@gmail.com','1c02e071c671727b51064d8d9e0cd33f','majidpeyravi@gmail.com','researcher','حقیقی','مجید','پیروی','','','active'),(77,'salmani_600@yahoo.com','25774065a3aaed697dafeae6d07ed510','salmani_600@yahoo.com','researcher','حقیقی','حسین','سلمانی','01227734250','','active'),(78,'nanocarpars@ymail.com','25774065a3aaed697dafeae6d07ed510','nanocarpars@ymail.com','company','حقیقی','حشمت الله','بهزادی','01227734250','','active'),(79,'mo..zabihi@yahoo.com','e10adc3949ba59abbe56e057f20f883e','mo..zabihi@yahoo.com','company','حقیقی','خزر الکتریک','','01213113941','','active'),(80,'he_behzadi@yahoo.com','5200e975b5acf88e065eea4fbea12a91','he_behzadi@yahoo.com','researcher','حقیقی','حشمت الله','بهزادی','01212210623','','removed'),(81,'rm.biqarar@gmail.com','e0c45ce728328d0019098764a5ed9563','rm.biqarar@gmail.com','company','حقیقی','sdfdsf','sdfdsfsdfdsfdsf','','','removed'),(82,'nanocarpars@yahoo.com','25774065a3aaed697dafeae6d07ed510','nanocarpars@yahoo.com','company','حقیقی','نانوغشا سیال ','','','','active'),(83,'f_kheirollahzade@yahoo.com','f427028297c5d9f319b803ec7a37289a','f_kheirollahzade@yahoo.com','researcher','حقیقی','فرهاد','خیراله زاده ','09112554225','','active'),(84,'iman_najafi65@yahoo.com','a67ed86edb7bb8b893639121ad9faa6e','iman_najafi65@yahoo.com','researcher','حقیقی','ایمان','','','','awaiting'),(85,'aminoarvin@gmail.com','b1ebdfa9d5d2ebfc96b0f6058e71b1a4','aminoarvin@gmail.com','company','حقیقی','امین آروین','','','','awaiting'),(90,'ahmadvalipour@gmail.com','54869046ce426c0570d659961685a06a','ahmadvalipour@gmail.com','researcher','حقوقی','احمد ولی پور','','','','awaiting'),(91,'mohsen354us@yahoo.com','9f22a7f1e5403cab2268cab715d98757','mohsen354us@yahoo.com','company','حقیقی','دانشگاه علمی کاربردی پاسارگاد','','','','awaiting');
/*!40000 ALTER TABLE `m_users` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'NO_AUTO_VALUE_ON_ZERO' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`rprb`@`localhost`*/ /*!50003 TRIGGER `rprb`.`users_on_insert_by_type_create_row` AFTER INSERT ON `rprb`.`m_users` FOR EACH ROW BEGIN
 IF NEW.type = 'researcher' THEN
    INSERT INTO researchers (user_id) values (new.user_id);
 ELSEIF NEW.type = 'company' THEN  
    INSERT INTO companies (user_id) values (new.user_id);
 END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `m_verifications`
--

DROP TABLE IF EXISTS `m_verifications`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `m_verifications` (
  `verify_id` int(11) NOT NULL AUTO_INCREMENT,
  `type` enum('forget','email') COLLATE utf8_persian_ci DEFAULT NULL,
  `email` varchar(50) COLLATE utf8_persian_ci DEFAULT NULL,
  `code` varchar(32) COLLATE utf8_persian_ci DEFAULT NULL,
  `user_id` int(6) DEFAULT NULL,
  `time` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  `verify` enum('yes','no') COLLATE utf8_persian_ci DEFAULT 'no',
  PRIMARY KEY (`verify_id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `m_verifications`
--

LOCK TABLES `m_verifications` WRITE;
/*!40000 ALTER TABLE `m_verifications` DISABLE KEYS */;
INSERT INTO `m_verifications` VALUES (1,'forget','rm.biqarar@gmail.com','50981c0de4258084bb21ee367e5a4b36',81,'2018-07-02 13:24:43','yes'),(2,'forget','he_behzadi@yahoo.com','802d18973906772a19c456b5985332e0',80,'2018-08-04 18:33:00','yes'),(3,'forget','he_behzadi@yahoo.com','802d18973906772a19c456b5985332e0',80,'2018-08-04 18:34:06','yes');
/*!40000 ALTER TABLE `m_verifications` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `notifications`
--

DROP TABLE IF EXISTS `notifications`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `notifications` (
  `id` bigint(11) unsigned NOT NULL AUTO_INCREMENT,
  `sender_id` int(6) DEFAULT NULL,
  `user_id` int(6) DEFAULT NULL,
  `title` varchar(200) COLLATE utf8_persian_ci DEFAULT NULL,
  `content` varchar(200) COLLATE utf8_persian_ci DEFAULT NULL,
  `url` varchar(100) COLLATE utf8_persian_ci DEFAULT NULL,
  `status` enum('read','unread') COLLATE utf8_persian_ci DEFAULT 'unread',
  `date` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  KEY `user_id` (`user_id`)
) ENGINE=InnoDB AUTO_INCREMENT=222 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `notifications`
--

LOCK TABLES `notifications` WRITE;
/*!40000 ALTER TABLE `notifications` DISABLE KEYS */;
INSERT INTO `notifications` VALUES (184,62,51,'تقاضاي جديد من براي پژوهش','','121','unread','2014-01-31 19:36:59'),(187,51,62,'ارسال پروپوزال توسط گروه پژوهشی','تقاضاي جديد من براي پژوهش\nتوضيحات پژوهش درخواستي\nدر زمينه 2\nوضعيت پژوهش تعريف شده و منتظر دريافت طرح هاي پيشنهادي پ','121','unread','2014-01-31 19:38:15'),(189,51,62,'قرارداد امضا شده و پژوهش شروع شد','تقاضاي جديد من براي پژوهش','121','unread','2014-01-31 19:41:41'),(191,51,62,'ارسال پروپوزال توسط پژوهشگر','جناب عوض زاده پژوهشگر محترم، شما می توانید برای این تقاضا پروپوزال خود را ارائه نمایید. بدین منظور از فرم زیر استفاده کنید.','116','unread','2014-02-01 20:26:36'),(197,51,62,'ارسال پروپوزال توسط پژوهشگر','عنوان پژوهش درخواستی شبکه برای تست تاریخ\r\nتوضیحات پژوهش درخواستی محصولات ارگونومیک در شبکه و تاثیرات آن','116','unread','2014-02-01 20:51:24'),(198,62,51,'تقاضای پژوهشی جدید پتروشیمی','توضیحی ندارم','122','unread','2014-02-04 02:39:25'),(199,62,65,'تقاضای پژوهشی جدید پتروشیمی','توضیحی ندارم','122','unread','2014-02-04 02:39:25'),(201,62,51,'نیاز من به یک پژوهش پتروشیمی','توضیح خاصی ندارم','123','unread','2014-02-04 02:48:36'),(202,62,65,'نیاز من به یک پژوهش پتروشیمی','توضیح خاصی ندارم','123','unread','2014-02-04 02:48:36'),(204,51,62,'ارسال پروپوزال توسط گروه پژوهشی','طرح من برای این تقاضا 1','123','unread','2014-02-04 02:49:45'),(205,62,51,'قرارداد ارسال شد','نیاز من به یک پژوهش پتروشیمی','123','unread','2014-02-04 03:00:06'),(206,51,62,'قرارداد امضا شده و پژوهش شروع شد','نیاز من به یک پژوهش پتروشیمی','123','unread','2014-02-04 03:20:30'),(207,51,62,'پژوهش به اتمام رسید','نیاز من به یک پژوهش پتروشیمی','123','unread','2014-02-04 03:20:52'),(208,67,62,'ارسال پروپوزال توسط پژوهشگر','توضیح من برای این مطلب','122','unread','2014-02-17 07:16:57'),(209,67,62,'ارسال پروپوزال توسط پژوهشگر','توضیح من برای این مطلبسسسس','122','unread','2014-02-17 07:17:25'),(210,67,62,'ارسال پروپوزال توسط پژوهشگر','توضیح من برای این مطلبسسسس 2','122','unread','2014-02-17 07:23:14'),(211,67,62,'ارسال پروپوزال توسط پژوهشگر','توضیح من برای این مطلبسسسس 2 صضثضص','122','unread','2014-02-17 07:28:39'),(212,78,76,'طراحی دوربین ترموگراف','دوربین ترموگراف کاربرد فراوانی در بازرسی غیرمخرب دارد. با توجه به معضلات .......................این یک تست است.','124','unread','2014-02-26 10:10:17'),(213,78,77,'طراحی دوربین ترموگراف','دوربین ترموگراف کاربرد فراوانی در بازرسی غیرمخرب دارد. با توجه به معضلات .......................این یک تست است.','124','unread','2014-02-26 10:10:17'),(215,79,76,'سیستم بازیافت پروتئین از ضایعات کشتارگاهی','به دلیل استفاده از روش حرارت غیر مستقیم برای پخت و بازیافت، دستگاهی که ترکیبات پروتئینی، معدنی و سایر خواص مفید آن حفظ شوده وضایعات در داخل دستگاه با حرارت کاملا یکنواخت پخته شده و رطوبت آن تا 8 درصد ','125','unread','2014-03-03 10:05:44'),(216,79,77,'سیستم بازیافت پروتئین از ضایعات کشتارگاهی','به دلیل استفاده از روش حرارت غیر مستقیم برای پخت و بازیافت، دستگاهی که ترکیبات پروتئینی، معدنی و سایر خواص مفید آن حفظ شوده وضایعات در داخل دستگاه با حرارت کاملا یکنواخت پخته شده و رطوبت آن تا 8 درصد ','125','unread','2014-03-03 10:05:44'),(217,51,62,'ارسال پروپوزال توسط پژوهشگر','این یک تست است','122','unread','2014-03-06 10:19:17'),(218,51,62,'ارسال پروپوزال توسط پژوهشگر','تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی ','122','unread','2014-03-06 10:20:14'),(219,51,62,'ارسال پروپوزال توسط پژوهشگر','تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی ','122','unread','2014-03-06 10:20:51'),(220,51,62,'ارسال پروپوزال توسط پژوهشگر','تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی ','122','unread','2014-03-06 10:21:40'),(221,62,79,'ارسال پروپوزال توسط پژوهشگر','ی ثبت شده برای پژوهش را در لیست زیر ','125','unread','2014-03-06 16:38:04');
/*!40000 ALTER TABLE `notifications` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `research_phase`
--

DROP TABLE IF EXISTS `research_phase`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `research_phase` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `research_id` int(6) DEFAULT NULL,
  `title` varchar(50) COLLATE utf8_persian_ci DEFAULT NULL,
  `start_date` date DEFAULT NULL,
  `end_date` date DEFAULT NULL,
  `price` float DEFAULT NULL,
  `researcher_end` enum('yes','no') COLLATE utf8_persian_ci DEFAULT 'no',
  `refree_end` enum('yes','no') COLLATE utf8_persian_ci DEFAULT 'no',
  `company_end` enum('yes','no') COLLATE utf8_persian_ci DEFAULT 'no',
  `content` text COLLATE utf8_persian_ci,
  `file` int(6) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `research_phase`
--

LOCK TABLES `research_phase` WRITE;
/*!40000 ALTER TABLE `research_phase` DISABLE KEYS */;
/*!40000 ALTER TABLE `research_phase` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `research_proposal`
--

DROP TABLE IF EXISTS `research_proposal`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `research_proposal` (
  `proposal_id` int(6) NOT NULL AUTO_INCREMENT,
  `sender_type` enum('researcher','group') COLLATE utf8_persian_ci DEFAULT 'researcher',
  `sender_id` int(6) DEFAULT NULL,
  `group_id` int(6) DEFAULT NULL COMMENT 'if sender_type=group then fill this',
  `research_id` int(6) DEFAULT NULL,
  `content` text COLLATE utf8_persian_ci,
  `price` varchar(20) COLLATE utf8_persian_ci DEFAULT NULL,
  `day` int(4) DEFAULT NULL,
  `file` int(11) DEFAULT NULL,
  `date` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  `status` enum('accept','reject','check') COLLATE utf8_persian_ci DEFAULT 'check',
  PRIMARY KEY (`proposal_id`)
) ENGINE=InnoDB AUTO_INCREMENT=48 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `research_proposal`
--

LOCK TABLES `research_proposal` WRITE;
/*!40000 ALTER TABLE `research_proposal` DISABLE KEYS */;
INSERT INTO `research_proposal` VALUES (8,'researcher',63,NULL,118,'این پروپوزال من است. این طرح اولیه توسط من ارسال شده است.',NULL,NULL,5,'2014-01-27 04:30:20','check'),(20,'researcher',63,NULL,118,'دور جدید مذاکرات هسته ای ایران و گروه 1+5 به احتمال فراوان در نیویورک برگزار می شود',NULL,NULL,0,'2014-01-27 16:19:28','check'),(21,'researcher',51,NULL,118,'شما می توانید برای این تقاضا پروپوزال خود را ارائه نمایید. بدین منظور از فرم زیر استفاده کنید.',NULL,NULL,0,'2014-01-27 16:22:21','check'),(22,'researcher',51,NULL,118,'شما می توانید برای این تقاضا پروپوزال خود را ارائه نمایید. بدین منظور از فرم زیر استفاده کنید. 2',NULL,NULL,0,'2014-01-27 16:23:10','check'),(23,'group',51,12,118,'شما می توانید برای این تقاضا پروپوزال خود را ارائه نمایید. بدین منظور از فرم زیر استفاده کنید.\nتوسط گروه ',NULL,NULL,10,'2014-01-27 16:23:51','check'),(24,'group',63,15,118,'جناب مجیدزاده پژوهشگر محترم، شما می توانید برای این تقاضا پروپوزال خود را ارائه نمایید. بدین منظور از فرم زیر استفاده کنید.',NULL,NULL,0,'2014-01-27 19:03:08','accept'),(25,'researcher',51,NULL,116,'جناب عوض زاده پژوهشگر محترم، شما می توانید برای این تقاضا پروپوزال خود را ارائه نمایید. ',NULL,NULL,0,'2014-01-27 21:12:19','check'),(27,'researcher',63,NULL,116,'اده پژوهشگر محترم، شما می توانید برای این تقاضا پروپوزال خود را ارائه نمایید. بدین م','200',30,0,'2014-01-28 04:11:25','check'),(28,'researcher',51,NULL,116,'توضيح من','2000',30,0,'2014-01-30 00:58:46','check'),(29,'group',51,12,121,'تقاضاي جديد من براي پژوهش\nتوضيحات پژوهش درخواستي\nدر زمينه 2\nوضعيت پژوهش تعريف شده و منتظر دريافت طرح هاي پيشنهادي پ','2000',50,0,'2014-01-31 19:38:15','accept'),(31,'researcher',51,NULL,116,'جناب عوض زاده پژوهشگر محترم، شما می توانید برای این تقاضا پروپوزال خود را ارائه نمایید. بدین منظور از فرم زیر استفاده کنید.','123',4,NULL,'2014-02-01 20:26:36','check'),(32,'researcher',51,NULL,116,'عنوان پژوهش درخواستی شبکه\r\nتوضیحات پژوهش درخواستی محصولات ارگونومیک در شبکه و تاثیرات آن\r\nدر زمینه 2\r\nوضعیت پژوهش تعریف شده و منتظر دریافت طرح های پیشنهادی پژوهشگران','123',3,NULL,'2014-02-01 20:28:51','check'),(33,'researcher',51,NULL,116,'عنوان پژوهش درخواستی شبکه\r\nتوضیحات پژوهش درخواستی محصولات ارگونومیک در شبکه و تاثیرات آن\r\nدر زمینه 2\r\nوضعیت پژوهش تعریف شده و منتظر دریافت طرح های پیشنهادی پژوهشگرانs ','123',3,NULL,'2014-02-01 20:29:46','check'),(34,'researcher',51,NULL,116,'عنوان پژوهش درخواستی شبکه\r\nتوضیحات پژوهش درخواستی محصولات ارگونومیک در شبکه و تاثیرات آن\r\n','123',3,NULL,'2014-02-01 20:30:57','check'),(35,'researcher',51,NULL,116,'عنوان پژوهش درخواستی شبکه\r\nتوضیحات پژوهش درخواستی محصولات ارگونومیک در شبکه و تاثیرات آن 2\r\n','123',3,NULL,'2014-02-01 20:32:42','check'),(36,'group',51,12,116,'عنوان پژوهش درخواستی شبکه برای تست تاریخ','1233',234,NULL,'2014-02-01 20:45:38','accept'),(37,'researcher',51,NULL,116,'عنوان پژوهش درخواستی شبکه برای تست تاریخ\r\nتوضیحات پژوهش درخواستی محصولات ارگونومیک در شبکه و تاثیرات آن','1233',234,NULL,'2014-02-01 20:51:24','check'),(38,'group',51,12,123,'طرح من برای این تقاضا 1','200',30,NULL,'2014-02-04 02:49:45','accept'),(39,'researcher',67,NULL,122,'توضیح من برای این مطلب','200',2,NULL,'2014-02-17 07:16:57','check'),(40,'researcher',67,NULL,122,'توضیح من برای این مطلبسسسس','200',2,NULL,'2014-02-17 07:17:25','check'),(41,'researcher',67,NULL,122,'توضیح من برای این مطلبسسسس 2','200',2,NULL,'2014-02-17 07:23:14','check'),(42,'researcher',67,NULL,122,'توضیح من برای این مطلبسسسس 2 صضثضص','200',2,NULL,'2014-02-17 07:28:39','check'),(43,'researcher',51,NULL,122,'این یک تست است','20',20,13,'2014-03-06 10:19:17','check'),(44,'researcher',51,NULL,122,'تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی ','30',50,14,'2014-03-06 10:20:14','check'),(45,'researcher',51,NULL,122,'تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی ','60',810,15,'2014-03-06 10:20:51','check'),(46,'researcher',51,NULL,122,'تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی تست نهایی ','201',30,17,'2014-03-06 10:21:40','check'),(47,'researcher',62,NULL,125,'ی ثبت شده برای پژوهش را در لیست زیر ','400',20,18,'2014-03-06 16:38:04','check');
/*!40000 ALTER TABLE `research_proposal` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'NO_AUTO_VALUE_ON_ZERO' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`rprb`@`localhost`*/ /*!50003 TRIGGER `rprb`.`research_proposal_on_insert_create_notify` AFTER INSERT ON `rprb`.`research_proposal` FOR EACH ROW BEGIN
 IF NEW.sender_type = 'researcher' THEN
  INSERT INTO notifications
    (sender_id, user_id, title, content, url)
    (select
    NEW.sender_id,
    researches.company_id,
    'ارسال پروپوزال توسط پژوهشگر',
    NEW.content,
    NEW.research_id
    from researches
    where research_id = NEW.research_id);
 ELSEIF NEW.sender_type = 'group' THEN 
   INSERT INTO notifications
    (sender_id, user_id, title, content, url)
    (select
    NEW.sender_id,
    researches.company_id,
    'ارسال پروپوزال توسط گروه پژوهشی',
    NEW.content,
    NEW.research_id
    from researches
    where research_id = NEW.research_id);
 END IF; 
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'NO_AUTO_VALUE_ON_ZERO' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`rprb`@`localhost`*/ /*!50003 TRIGGER `rprb`.`research_proposal_on_update_with_notify` AFTER UPDATE ON `rprb`.`research_proposal` FOR EACH ROW BEGIN
IF NEW.status <> OLD.status THEN
 IF NEW.status = 'accept' THEN
    UPDATE researches SET status = 'contract', sender_type = NEW.sender_type, sender_id = NEW.sender_id, group_id = New.group_id, file = NEW.file, price = New.price  WHERE research_id = New.research_id;
 ELSEIF NEW.status = 'reject' THEN
  INSERT INTO notifications
    (sender_id, user_id, title, content, url)
    (select
    NEW.sender_id,
    researches.company_id,
    'پروپوزال شما رد شد',
    NEW.content,
    NEW.research_id
    from researches
    where research_id = NEW.research_id);
 END IF;
END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `researcher_books`
--

DROP TABLE IF EXISTS `researcher_books`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `researcher_books` (
  `id` int(6) NOT NULL AUTO_INCREMENT,
  `user_id` int(6) DEFAULT NULL,
  `title` varchar(150) COLLATE utf8_persian_ci DEFAULT NULL,
  `publisher` varchar(150) COLLATE utf8_persian_ci DEFAULT NULL,
  `year` smallint(4) DEFAULT NULL,
  `type` enum('نویسنده','گردآورنده','مترجم') COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `researcher_books`
--

LOCK TABLES `researcher_books` WRITE;
/*!40000 ALTER TABLE `researcher_books` DISABLE KEYS */;
INSERT INTO `researcher_books` VALUES (2,51,'کتاب','انتشارات 22',1390,'گردآورنده'),(3,51,'کتاب 2','انتشارات 2',1370,'مترجم'),(5,77,'روش شناسی پژوهش در علوم فنی ومهندسی','دانشگاه علمی وکاربردی',1392,'نویسنده'),(6,83,'فناوری و سیستم حرفه و فن سالهای اول و دوم و سوم راهنمایی ','مرکز چاپ و نشر کتابهای درسی وزارت آموزش و پرورش',1390,'نویسنده');
/*!40000 ALTER TABLE `researcher_books` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `researcher_contracts`
--

DROP TABLE IF EXISTS `researcher_contracts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `researcher_contracts` (
  `id` int(6) NOT NULL AUTO_INCREMENT,
  `user_id` int(6) DEFAULT NULL,
  `name` varchar(150) COLLATE utf8_persian_ci DEFAULT NULL,
  `tel` varchar(11) COLLATE utf8_persian_ci DEFAULT NULL,
  `title` varchar(150) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `researcher_contracts`
--

LOCK TABLES `researcher_contracts` WRITE;
/*!40000 ALTER TABLE `researcher_contracts` DISABLE KEYS */;
INSERT INTO `researcher_contracts` VALUES (1,51,'وزارت علوم','123','سامانه پژوهشی'),(3,77,'وزارت علوم تحقیقات و فن آوری','01218223354','ضرورت اجرای پژوهش به شیوه تقاضا محور'),(4,77,'شرکت صنعتی سولار','01212210622','ممیزی انرژی سیستم تولید'),(5,51,NULL,NULL,NULL);
/*!40000 ALTER TABLE `researcher_contracts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `researcher_patents`
--

DROP TABLE IF EXISTS `researcher_patents`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `researcher_patents` (
  `id` int(6) NOT NULL AUTO_INCREMENT,
  `user_id` int(6) DEFAULT NULL,
  `title` varchar(150) COLLATE utf8_persian_ci DEFAULT NULL,
  `country` varchar(150) COLLATE utf8_persian_ci DEFAULT NULL,
  `code` varchar(150) COLLATE utf8_persian_ci DEFAULT NULL,
  `date` varchar(11) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `code` (`code`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `researcher_patents`
--

LOCK TABLES `researcher_patents` WRITE;
/*!40000 ALTER TABLE `researcher_patents` DISABLE KEYS */;
INSERT INTO `researcher_patents` VALUES (2,51,'اختراع 1','ایران','123532','2014-01-23'),(4,51,'جدید','من','تو','1369/12/15'),(7,63,'پ1','پ2','3','0000-00-00'),(8,51,'','','','0000-00-00'),(13,51,'sdas','asda','2412','0000-00-00'),(14,77,'تصفیه و بازیافت دود و انرژی از اگزور بویلرهای صنعتی','اداره ثبت اسناد ','40333655','0000-00-00');
/*!40000 ALTER TABLE `researcher_patents` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `researcher_seminars`
--

DROP TABLE IF EXISTS `researcher_seminars`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `researcher_seminars` (
  `id` int(6) NOT NULL AUTO_INCREMENT,
  `user_id` int(6) DEFAULT NULL,
  `name` varchar(150) COLLATE utf8_persian_ci DEFAULT NULL,
  `date` varchar(11) COLLATE utf8_persian_ci DEFAULT NULL,
  `title` varchar(150) COLLATE utf8_persian_ci DEFAULT NULL,
  `type` enum('پوستر','سخنرانی') COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `researcher_seminars`
--

LOCK TABLES `researcher_seminars` WRITE;
/*!40000 ALTER TABLE `researcher_seminars` DISABLE KEYS */;
INSERT INTO `researcher_seminars` VALUES (1,51,'سمینار اول','1380','عنوان مقاله','سخنرانی'),(2,77,'همایش بین المللی آموزش','1391/12/18','نقش وجایگاه مدرسان بین رشته ای در علوم مهندسی','سخنرانی'),(3,77,'نهضت نرم افزار،چالشها و فرصتها','1392/3/20','کاربرد نانوسیم های طلا و نقره در طراحی مدولاتورهای اپتیکی','سخنرانی'),(4,84,'سمینار مهندسی نفت','27 اردی بهش','بررسی تاثیر فراصوت','سخنرانی');
/*!40000 ALTER TABLE `researcher_seminars` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `researcher_workshops`
--

DROP TABLE IF EXISTS `researcher_workshops`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `researcher_workshops` (
  `id` int(6) NOT NULL AUTO_INCREMENT,
  `user_id` int(6) DEFAULT NULL,
  `name` varchar(150) COLLATE utf8_persian_ci DEFAULT NULL,
  `date` varchar(11) COLLATE utf8_persian_ci DEFAULT NULL,
  `title` varchar(150) COLLATE utf8_persian_ci DEFAULT NULL,
  `type` enum('دبیر','رئیس کارگاه','عضو کمیته علمی','عضو کمیته داوری','عضو کمیته اجرایی') COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `researcher_workshops`
--

LOCK TABLES `researcher_workshops` WRITE;
/*!40000 ALTER TABLE `researcher_workshops` DISABLE KEYS */;
INSERT INTO `researcher_workshops` VALUES (1,51,'کارگاه اول','1369/15/20','برگزار کننده','عضو کمیته علمی');
/*!40000 ALTER TABLE `researcher_workshops` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `researchers`
--

DROP TABLE IF EXISTS `researchers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `researchers` (
  `user_id` int(6) NOT NULL,
  `type` enum('حقیقی','حقوقی') COLLATE utf8_persian_ci DEFAULT 'حقیقی',
  `education` enum('دیپلم','فوق دیپلم','کارشناسی','کارشناسی ارشد','دکتری') COLLATE utf8_persian_ci DEFAULT NULL,
  `field` varchar(100) COLLATE utf8_persian_ci DEFAULT NULL,
  `year` smallint(4) DEFAULT NULL,
  `country` varchar(15) COLLATE utf8_persian_ci DEFAULT NULL,
  `university` varchar(15) COLLATE utf8_persian_ci DEFAULT NULL,
  `adjusted` enum('مربی','استادیار','دانشیار','استاد') COLLATE utf8_persian_ci DEFAULT NULL,
  `isi` int(3) DEFAULT NULL,
  `witness` int(6) DEFAULT NULL,
  `lwitness` int(6) DEFAULT NULL,
  `val_one` varchar(20) COLLATE utf8_persian_ci DEFAULT NULL,
  `val_two` varchar(20) COLLATE utf8_persian_ci DEFAULT NULL,
  `val_three` varchar(20) COLLATE utf8_persian_ci DEFAULT NULL,
  `activity_id` int(6) DEFAULT NULL,
  `about` varchar(300) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`user_id`),
  UNIQUE KEY `user_id` (`user_id`),
  KEY `user_id_2` (`user_id`),
  KEY `user_id_3` (`user_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `researchers`
--

LOCK TABLES `researchers` WRITE;
/*!40000 ALTER TABLE `researchers` DISABLE KEYS */;
INSERT INTO `researchers` VALUES (51,'حقیقی','کارشناسی','نرم افزار',1390,'ایران','تهران','استادیار',5,4,1,'ss','456','9999',3,'سلام. این درباره من است'),(76,'حقیقی',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'123456',8,NULL),(77,'حقیقی','کارشناسی ارشد','فیزیک',1385,'ایران','تهران',NULL,2,NULL,NULL,'1358','2142068642','40338661',8,NULL),(80,'حقیقی',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'60526745',3,NULL),(83,'حقیقی','کارشناسی ارشد','مهندسی مکانیک - ساخت و تولید',1379,'ایران','دانشگاه صنعتی خ',NULL,1,NULL,NULL,'1379','2141044359','12483394',10,NULL),(84,'حقیقی',NULL,'مهندسی نفت',1392,'ایران','صنعتی شریف',NULL,14,NULL,NULL,NULL,NULL,'123432',1,NULL),(90,'حقیقی',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'1111',16,NULL);
/*!40000 ALTER TABLE `researchers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `researches`
--

DROP TABLE IF EXISTS `researches`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `researches` (
  `research_id` int(6) NOT NULL AUTO_INCREMENT,
  `company_id` int(6) DEFAULT NULL,
  `title` varchar(150) COLLATE utf8_persian_ci DEFAULT NULL,
  `content` varchar(500) COLLATE utf8_persian_ci DEFAULT NULL,
  `activity_id` int(6) DEFAULT NULL,
  `status` enum('declared','accept','phase','contract','study','ended','deleted') COLLATE utf8_persian_ci DEFAULT 'declared',
  `sender_type` enum('researcher','group') COLLATE utf8_persian_ci DEFAULT NULL,
  `sender_id` int(6) DEFAULT NULL,
  `group_id` int(6) DEFAULT NULL,
  `start_date` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  `accept_date` datetime DEFAULT NULL,
  `file` int(11) DEFAULT NULL,
  `price` float unsigned DEFAULT NULL,
  `contract_date` datetime DEFAULT NULL,
  `study_date` datetime DEFAULT NULL,
  `ended_date` datetime DEFAULT NULL,
  `file_ended` int(11) DEFAULT NULL,
  PRIMARY KEY (`research_id`),
  UNIQUE KEY `company_id` (`company_id`,`title`,`status`),
  UNIQUE KEY `company_id_2` (`company_id`,`title`),
  KEY `id` (`research_id`)
) ENGINE=InnoDB AUTO_INCREMENT=126 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `researches`
--

LOCK TABLES `researches` WRITE;
/*!40000 ALTER TABLE `researches` DISABLE KEYS */;
INSERT INTO `researches` VALUES (116,62,'شبکه','محصولات ارگونومیک در شبکه و تاثیرات آن',2,'contract','group',51,12,NULL,NULL,NULL,1233,'2014-02-03 10:16:34','2014-01-30 04:36:35',NULL,NULL),(118,62,'چاه نفت','محصولات ارگونومیک در شبکه و تاثیرات آن',1,'ended','group',63,15,NULL,'2014-01-28 05:22:43',2,700,'2014-01-28 07:09:39','2014-01-28 07:56:46','2014-01-28 07:58:30',NULL),(121,62,'تقاضاي جديد من براي پژوهش','',2,'study','group',51,12,'2014-01-31 19:36:59',NULL,0,2000,'2014-01-31 23:09:20','2014-01-31 23:11:41',NULL,NULL),(122,62,'تقاضای پژوهشی جدید پتروشیمی','توضیحی ندارم',2,'declared',NULL,NULL,NULL,'2014-02-04 02:39:25',NULL,NULL,NULL,NULL,NULL,NULL,NULL),(123,62,'نیاز من به یک پژوهش پتروشیمی','توضیح خاصی ندارم',2,'ended','group',51,12,'2014-02-04 02:48:36',NULL,NULL,200,'2014-02-04 06:30:06','2014-02-04 06:50:30','2014-02-04 06:50:52',NULL),(124,78,'طراحی دوربین ترموگراف','دوربین ترموگراف کاربرد فراوانی در بازرسی غیرمخرب دارد. با توجه به معضلات .......................این یک تست است.',8,'declared',NULL,NULL,NULL,'2014-02-26 10:10:17',NULL,NULL,NULL,NULL,NULL,NULL,NULL),(125,79,'سیستم بازیافت پروتئین از ضایعات کشتارگاهی','به دلیل استفاده از روش حرارت غیر مستقیم برای پخت و بازیافت، دستگاهی که ترکیبات پروتئینی، معدنی و سایر خواص مفید آن حفظ شوده وضایعات در داخل دستگاه با حرارت کاملا یکنواخت پخته شده و رطوبت آن تا 8 درصد کاهش  یابد و راحت می توان آن را آسیاب و بسته بندی نمود.\nبا توجه به اینکه پروتئین، چربی، مواد معدنی و سایر ترکیبات مفید در پودر به دست آمده حفظ می شود و در طی پروسه پخت تمام میکروبهای مضر و قارچ ها از بین می رود.پودر حاصله را می توان در جیره غذایی مرغ تخم گذار و گوشتی، پرورش ماهی استفاده نمود',8,'declared',NULL,NULL,NULL,'2014-03-03 10:05:44',NULL,NULL,NULL,NULL,NULL,NULL,NULL);
/*!40000 ALTER TABLE `researches` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'NO_AUTO_VALUE_ON_ZERO' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`rprb`@`localhost`*/ /*!50003 TRIGGER `rprb`.`research_on_insert_create_notify` AFTER INSERT ON `rprb`.`researches` FOR EACH ROW BEGIN    
 INSERT INTO notifications 
    (sender_id, user_id, title, content, url) 
    (select
    NEW.company_id,
    researchers.user_id,
    NEW.title,
    NEW.content,
    NEW.research_id
    from researchers
    where activity_id = NEW.activity_id);
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'NO_AUTO_VALUE_ON_ZERO' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`rprb`@`localhost`*/ /*!50003 TRIGGER `rprb`.`research_on_update_status_with_notify` BEFORE UPDATE ON `rprb`.`researches` FOR EACH ROW BEGIN
IF NEW.status <> OLD.status THEN
 IF NEW.status = 'accept' THEN
  INSERT INTO notifications (sender_id, user_id, title, content, url)
    values(NEW.company_id, NEW.sender_id, 'پروپوزال شما مورد تایید قرار گرفت', NEW.title, NEW.research_id);
	set new.accept_date = now();
 ELSEIF NEW.status = 'phase' THEN
  INSERT INTO notifications (sender_id, user_id, title, content, url)
    values(NEW.sender_id, NEW.company_id, 'فاز بندی مشخص شد', NEW.title, NEW.research_id);
 ELSEIF NEW.status = 'contract' THEN
  INSERT INTO notifications (sender_id, user_id, title, content, url)
    values(NEW.company_id, NEW.sender_id, 'قرارداد ارسال شد', NEW.title, NEW.research_id);
	set new.contract_date = now();
 ELSEIF NEW.status = 'study' THEN
  INSERT INTO notifications (sender_id, user_id, title, content, url)
    values(NEW.sender_id, NEW.company_id, 'قرارداد امضا شده و پژوهش شروع شد', NEW.title, NEW.research_id);
	set new.study_date = now();
 ELSEIF NEW.status = 'ended' THEN
  INSERT INTO notifications (sender_id, user_id, title, content, url)
    values(NEW.sender_id, NEW.company_id, 'پژوهش به اتمام رسید', NEW.title, NEW.research_id);
	set new.ended_date = now();
 ELSEIF NEW.status = 'deleted' THEN
  INSERT INTO notifications (sender_id, user_id, title, content, url)
    values(NEW.company_id, NEW.sender_id, 'تقاضای پژوهشی شما حذف شد', NEW.title, NEW.research_id);
 END IF;
END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-11-11 16:54:12
