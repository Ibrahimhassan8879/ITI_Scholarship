--Lab 5 Part 2
use AdventureWorks2012

--Query 1 --------------------------------------------------------------------------------------------------------------------------------
SELECT SalesOrderID, ShipDate FROM Sales.SalesOrderHeader
WHERE ShipDate BETWEEN '7/28/2002' AND '7/29/2014'

--Query 2 --------------------------------------------------------------------------------------------------------------------------------
SELECT ProductID, Name FROM Production.Product WHERE StandardCost < 110.00 

--Query 3 --------------------------------------------------------------------------------------------------------------------------------
SELECT ProductID, Name FROM Production.Product WHERE Weight IS NULL

--Query 4 --------------------------------------------------------------------------------------------------------------------------------
SELECT * FROM Production.Product WHERE Color IN ('Silver','Black','Red')

--Query 5 --------------------------------------------------------------------------------------------------------------------------------
SELECT * FROM Production.Product WHERE Name LIKE 'B%'

--Query 6 --------------------------------------------------------------------------------------------------------------------------------
UPDATE Production.ProductDescription
SET Description = 'Chromoly steel_High of defects'
WHERE ProductDescriptionID = 3

SELECT Description FROM Production.ProductDescription WHERE Description LIKE '%[_]%'

--Query 7 --------------------------------------------------------------------------------------------------------------------------------
SELECT SUM(TotalDue) AS TotalDue FROM Sales.SalesOrderHeader
GROUP BY OrderDate
HAVING OrderDate BETWEEN '1/7/2001' AND '7/31/2014'

--Query 8 --------------------------------------------------------------------------------------------------------------------------------
SELECT DISTINCT HireDate FROM HumanResources.Employee 

--Query 9 --------------------------------------------------------------------------------------------------------------------------------
SELECT AVG(DISTINCT ListPrice) AS [Average List Price] FROM Production.Product

--Query 10 --------------------------------------------------------------------------------------------------------------------------------
SELECT CONCAT('The ',Name, ' is Only! ',ListPrice) FROM Production.Product
WHERE ListPrice BETWEEN 100 AND 120
ORDER BY ListPrice

--Query 11 --------------------------------------------------------------------------------------------------------------------------------
SELECT rowguid, Name, SalesPersonID INTO [Store_Archive]
FROM Sales.Store

--Query for the new table
DROP Table Store_Archive


--same Query without transferring data
SELECT rowguid, Name, SalesPersonID INTO [Store_Archive]
FROM Sales.Store
WHERE 1 = 100

--Query 12 --------------------------------------------------------------------------------------------------------------------------------
SELECT CONVERT(VARCHAR(30),GETDATE())
UNION
SELECT FORMAT(GETDATE(),'YYYY-DD-MM')
UNION
SELECT FORMAT(GETDATE(),'MM-DD-YYYY')
