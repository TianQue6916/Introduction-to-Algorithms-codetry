-- ============================================
-- 1. 切换到练习数据库
-- ============================================
USE MyStudyDB;
GO

-- ============================================
-- 2. 安全删除旧表（如果存在）
-- ============================================
IF OBJECT_ID('dbo.SalesRecords', 'U') IS NOT NULL
BEGIN
    DROP TABLE dbo.SalesRecords;
    PRINT N'旧表 SalesRecords 已删除。';
END
GO

-- ============================================
-- 3. 创建新的销售记录表（优化版）
-- ============================================
CREATE TABLE dbo.SalesRecords (
    SaleID INT IDENTITY(1,1) PRIMARY KEY,      -- 自增主键，唯一标识每笔销售
    ProductName NVARCHAR(100) NOT NULL,        -- 产品名（不允许为空）
    Category NVARCHAR(50) NOT NULL,            -- 类别（不允许为空）
    UnitPrice DECIMAL(10, 2) NOT NULL CHECK (UnitPrice > 0), -- 单价，必须大于0
    Quantity INT NOT NULL CHECK (Quantity > 0),-- 数量，必须大于0
    -- 计算列：自动计算销售额（单价*数量），此列数据由系统自动生成，无需插入
    SaleAmount AS (UnitPrice * Quantity) PERSISTED, 
    CustomerRegion NVARCHAR(50) DEFAULT N'未知地区', -- 客户地区，默认值
    SaleDate DATE NOT NULL DEFAULT GETDATE(),  -- 销售日期，默认为当天
    Rating INT NULL CHECK (Rating BETWEEN 1 AND 5) -- 评分，可为空，范围1-5
);
PRINT N'新表 SalesRecords 结构创建成功。';
GO

-- ============================================
-- 4. 开始事务，准备插入10000条模拟数据
-- ============================================
SET NOCOUNT ON; -- 禁止返回每行操作的影响行数消息，提升性能
BEGIN TRY
    BEGIN TRANSACTION; -- 开始事务

    DECLARE @counter INT = 0;
    DECLARE @batchSize INT = 2000; -- 每批次插入2000条，平衡性能与事务日志
    DECLARE @totalRows INT = 10000;

    PRINT N'开始生成 ' + CAST(@totalRows AS NVARCHAR) + N' 条模拟数据...';

    WHILE @counter < @totalRows
    BEGIN
        -- 使用INSERT...SELECT一次性插入一个批次，效率远高于循环内单条INSERT
        INSERT INTO dbo.SalesRecords (ProductName, Category, UnitPrice, Quantity, CustomerRegion, SaleDate, Rating)
        SELECT TOP (@batchSize)
            -- 产品名：从预设数组中随机选取
            CHOOSE(1 + CAST(RAND(CHECKSUM(NEWID())) * 5 AS INT), N'笔记本电脑', N'智能手机', N'无线耳机', N'平板电脑', N'智能手表'),
            -- 类别：从预设数组中随机选取
            CHOOSE(1 + CAST(RAND(CHECKSUM(NEWID())) * 3 AS INT), N'电子产品', N'数码配件', N'智能设备'),
            -- 单价：300.00 - 9999.99 之间的随机数
            CAST(RAND(CHECKSUM(NEWID())) * 9700 + 300 AS DECIMAL(10,2)),
            -- 数量：1 - 20 之间的随机整数
            1 + CAST(RAND(CHECKSUM(NEWID())) * 20 AS INT),
            -- 地区：从预设数组中随机选取（1/10的概率为NULL，模拟数据缺失）
            CASE WHEN RAND(CHECKSUM(NEWID())) > 0.1 THEN CHOOSE(1 + CAST(RAND(CHECKSUM(NEWID())) * 4 AS INT), N'华北', N'华东', N'华南', N'西部') ELSE NULL END,
            -- 销售日期：过去365天内的随机一天
            DATEADD(DAY, -CAST(RAND(CHECKSUM(NEWID())) * 365 AS INT), GETDATE()),
            -- 评分：1-5之间的随机整数（有30%的概率为NULL，模拟未评分情况）
            CASE WHEN RAND(CHECKSUM(NEWID())) > 0.3 THEN 1 + CAST(RAND(CHECKSUM(NEWID())) * 5 AS INT) ELSE NULL END
        FROM sys.all_columns a CROSS JOIN sys.all_columns b; -- 用于生成足够多的行以供SELECT TOP选取

        SET @counter = @counter + @batchSize;
        PRINT N'已插入 ' + CAST(@counter AS NVARCHAR) + N' 条数据...';
    END

    COMMIT TRANSACTION; -- 提交事务，确认所有更改
    PRINT N'事务提交成功！10000 条数据已全部插入。';
END TRY
BEGIN CATCH
    -- 如果发生任何错误，回滚事务，数据库将回到插入前的状态
    ROLLBACK TRANSACTION;
    PRINT N'数据插入过程中发生错误，所有更改已回滚。';
    -- 输出详细的错误信息
    PRINT N'错误号：' + CAST(ERROR_NUMBER() AS NVARCHAR);
    PRINT N'错误信息：' + ERROR_MESSAGE();
END CATCH

SET NOCOUNT OFF; -- 恢复设置
GO

-- ============================================
-- 5. 数据验证与示例查询
-- ============================================
PRINT N'开始数据验证...';
-- 5.1 查询总行数
SELECT COUNT(*) AS [总记录数] FROM dbo.SalesRecords;
-- 5.2 查看前10条样本数据
SELECT TOP 10 
    SaleID, 
    ProductName, 
    Category, 
    UnitPrice, 
    Quantity,
    SaleAmount, -- 注意看计算列是否正确
    CustomerRegion, 
    SaleDate, 
    Rating
FROM dbo.SalesRecords 
ORDER BY SaleID;
-- 5.3 查看数据概览（各品类销售笔数）
SELECT 
    Category AS [产品类别],
    COUNT(*) AS [销售笔数],
    AVG(UnitPrice) AS [平均单价],
    SUM(SaleAmount) AS [销售总额]
FROM dbo.SalesRecords 
GROUP BY Category 
ORDER BY [销售总额] DESC;
GO

PRINT N'脚本执行完毕！';


