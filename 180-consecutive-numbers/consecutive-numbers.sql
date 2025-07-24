# return the consecutive num only when 3 of them are one after other 
SELECT DISTINCT Num AS ConsecutiveNums
FROM Logs l
WHERE 
    (SELECT Num FROM Logs WHERE Id = l.Id + 1) = l.Num
    AND 
    (SELECT Num FROM Logs WHERE Id = l.Id + 2) = l.Num;
