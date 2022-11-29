#include "mainpage.h"
#include "ui_mainpage.h"
#include "signin_page.h"
//#include <QDebug>

mainpage::mainpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainpage)
{
    ui->setupUi(this);

    // 连接数据库
    this->mydatabase.getConnection();

    // 为表格模式指针指定内存
    this->dataTableModel = new QStandardItemModel();

    // 设置表格
    // this->setuinfoTableInfo();

    ui->stackedWidget->setCurrentIndex(0);
}

mainpage::~mainpage()
{
    delete ui;
}

void mainpage::setuinfoTableInfo()
{
    // 设置表头
    this->dataTableModel->setHorizontalHeaderItem(0, new QStandardItem("用户账号"));
    this->dataTableModel->setHorizontalHeaderItem(1, new QStandardItem("用户密码"));
    this->dataTableModel->setHorizontalHeaderItem(2, new QStandardItem("用户姓名"));
    this->dataTableModel->setHorizontalHeaderItem(3, new QStandardItem("用户类型"));

    // 设置表格信息
    // this->getDatabaseInfo();

    // 设置列宽
    ui->shopTable->setColumnWidth(0, 200);
    ui->shopTable->setColumnWidth(1, 200);
    ui->shopTable->setColumnWidth(2, 200);
    ui->shopTable->setColumnWidth(3, 200);

    // 设置表格只读属性
    ui->shopTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 最后将设计化的表格，装载在表格上
    ui->shopTable->setModel(this->dataTableModel);
}

/*
void mainpage::getDatabaseInfo()
{
    // 这个好像没啥用了
    qDebug() << "已进入获取商品界面!!!!!!!!!!!!!!!";
    // 第一步，从数据库中获取信息
    QSqlQuery sql;
    sql.prepare("select * from goods");
    sql.exec();

    int row = 0;        // 定义变量row表示表格行数
    while (sql.next())
    {
        this->dataTableModel->setItem(row, 0, new QStandardItem(sql.value("信息").toString()));

    }
}
*/

void mainpage::on_umaction_triggered()
{
    qDebug() << "已进入管理员用户管理界面";
    QSqlQuery sql;
    sql.prepare("select * from m_info");
    sql.exec();

    this->dataTableModel->clear();
    this->setuinfoTableInfo();

    int row = 0;        // 定义变量row表示表格行数


    while (sql.next())
    {
        this->dataTableModel->setItem(row, 0, new QStandardItem(sql.value("usernumber").toString()));
        this->dataTableModel->setItem(row, 1, new QStandardItem(sql.value("userpassword").toString()));
        this->dataTableModel->setItem(row, 2, new QStandardItem(sql.value("username").toString()));
        this->dataTableModel->setItem(row, 3, new QStandardItem(sql.value("usertype").toString()));
        row++;
    }
    sql.clear();
}

// 工具栏中修改密码界面
void mainpage::on_actionmima_triggered()
{
    // 逻辑：点击进入修改密码，界面不变，然后改变下方的层级窗口，通过文本框输入，到对应sql的update语句，更新表内容
    ui->stackedWidget->setCurrentIndex(1);
}

// 工具栏中重新登录
void mainpage::on_actiondenglu_triggered()
{
    this->~mainpage();
    SignIn_Page* w = new SignIn_Page();
    w->show();
}

// stackedWidget中下标为1的界面这种的“修改”按钮
void mainpage::on_pushButton1_submit_clicked()
{
    QString number = ui->lineEdit1_account->text();
    QString name = ui->lineEdit1_name->text();
    QString firstp = ui->lineEdit1_first->text();
    QString nextp = ui->lineEdit1_next->text();
    QString type = ui->lineEdit1_type->text();

    qDebug() << number;
    qDebug() << name;
    qDebug() << firstp;
    qDebug() << nextp;
    qDebug() << type;

    QSqlQuery sql;

    //sql.prepare("update m_info set userpassword =:nextp, username =:name where usernumber =:number AND userpassword =:firstp");
    // 调用存储过程
    sql.prepare("call update_m_info(:number, :firstp, :nextp, :name, :type)");

    sql.bindValue(":number", number);
    sql.bindValue(":name", name);
    sql.bindValue(":firstp", firstp);
    sql.bindValue(":nextp", nextp);
    sql.bindValue(":type", type);


    bool addIF = sql.exec();
    if(addIF)
    {
        qDebug() << "修改成功！";
        mainpage::on_umaction_triggered();
    }
    else
    {
        qDebug() << "修改失败!";
    }
}

void mainpage::setgoodsTableInfo()
{
    // 设置表头
    this->dataTableModel->setHorizontalHeaderItem(0, new QStandardItem("商品id"));
    this->dataTableModel->setHorizontalHeaderItem(1, new QStandardItem("商品名称"));
    this->dataTableModel->setHorizontalHeaderItem(2, new QStandardItem("商品个数"));
    this->dataTableModel->setHorizontalHeaderItem(3, new QStandardItem("商品供应价格"));
    this->dataTableModel->setHorizontalHeaderItem(4, new QStandardItem("商品售价"));
    this->dataTableModel->setHorizontalHeaderItem(5, new QStandardItem("商品描述"));
    this->dataTableModel->setHorizontalHeaderItem(6, new QStandardItem("供应商名称"));
    this->dataTableModel->setHorizontalHeaderItem(7, new QStandardItem("日期"));

    // 设置列宽
    ui->shopTable->setColumnWidth(0, 200);
    ui->shopTable->setColumnWidth(1, 200);
    ui->shopTable->setColumnWidth(2, 200);
    ui->shopTable->setColumnWidth(3, 200);
    ui->shopTable->setColumnWidth(4, 200);
    ui->shopTable->setColumnWidth(5, 500);
    ui->shopTable->setColumnWidth(6, 500);
    ui->shopTable->setColumnWidth(7, 500);

    // 设置表格只读属性
    ui->shopTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 最后将设计化的表格，装载在表格上
    ui->shopTable->setModel(this->dataTableModel);
}


// 上方工具栏的商品信息
void mainpage::on_actionxinxi_triggered()
{
    this->dataTableModel->clear();
    // 切换堆栈窗口下标到2
    ui->stackedWidget->setCurrentIndex(2);

    // 点击商品信息后，需要商品信息的数据库加载出来

    qDebug() << "已进入商品信息界面";
    QSqlQuery sql;
    sql.prepare("call look_goods_manage_procedure()");
    sql.exec();

    this->setgoodsTableInfo();

    int row = 0;        // 定义变量row表示表格行数


    while (sql.next())
    {
        this->dataTableModel->setItem(row, 0, new QStandardItem(sql.value("goods_id").toString()));
        this->dataTableModel->setItem(row, 1, new QStandardItem(sql.value("goods_name").toString()));
        this->dataTableModel->setItem(row, 2, new QStandardItem(sql.value("goods_number").toString()));
        this->dataTableModel->setItem(row, 3, new QStandardItem(sql.value("market_price").toString()));
        this->dataTableModel->setItem(row, 4, new QStandardItem(sql.value("shop_price").toString()));
        this->dataTableModel->setItem(row, 5, new QStandardItem(sql.value("goods_desc").toString()));
        this->dataTableModel->setItem(row, 6, new QStandardItem(sql.value("supplier_name").toString()));
        this->dataTableModel->setItem(row, 7, new QStandardItem(sql.value("date").toString()));
        row++;
    }
    sql.clear();
}


//查询
void mainpage::on_pushButton2_search_clicked()
{
    // 查的功能
    QString id = ui->lineEdit2_ID->text();
    QString name = ui->lineEdit2_Gname->text();
    if(id == "" && name == "")
    {
        // 若id与name框为空，则默认为刷新商品
        mainpage::on_actionxinxi_triggered();
    }
    else
    {
        QSqlQuery sql;
        sql.prepare("call search_goods_manage_procedure(:id, :name)");
        sql.bindValue(":name", name);
        sql.bindValue(":id", id);
        qDebug() << id;
        qDebug() << name;
        bool addIF = sql.exec();
        if(addIF)
        {
            qDebug() << "查找成功！";
//          QStringList newRowData;
            int row = 0;
            this->dataTableModel->clear();
            this->setgoodsTableInfo();
//                newRowData << sql.value("goods_id").toString() << sql.value("goods_name").toString() << sql.value("goods_number").toString()
//                           << sql.value("market_price").toString() << sql.value("shop_price").toString() << sql.value("supplier_name").toString();
//                qDebug() << "22222222";
            // 执行sql操作时候，数据指针是停留在数据之前的，因此，我们需要移动一下指针
            while(sql.next())
            {
                this->dataTableModel->setItem(row, 0, new QStandardItem(sql.value("goods_id").toString()));
                this->dataTableModel->setItem(row, 1, new QStandardItem(sql.value("goods_name").toString()));
                this->dataTableModel->setItem(row, 2, new QStandardItem(sql.value("goods_number").toString()));
                this->dataTableModel->setItem(row, 3, new QStandardItem(sql.value("market_price").toString()));
                this->dataTableModel->setItem(row, 4, new QStandardItem(sql.value("shop_price").toString()));
                this->dataTableModel->setItem(row, 5, new QStandardItem(sql.value("goods_desc").toString()));
                this->dataTableModel->setItem(row, 6, new QStandardItem(sql.value("supplier_name").toString()));
                this->dataTableModel->setItem(row, 7, new QStandardItem(sql.value("date").toString()));
            }
            sql.clear();
        }
        else
        {
            qDebug() << "查找失败!";
        }
    }
}

// 修改售价按钮
void mainpage::on_pushButton2_modify_clicked()
{
    QString id = ui->lineEdit2_ID->text();
    QString name = ui->lineEdit2_Gname->text();
    QString price = ui->lineEdit2_Gprice->text();

    if(id == "" || name == "" || price == "")
    {
        qDebug() << "某个输入框输入为空";
    }
    else
    {
        QSqlQuery sql;
        //sql.prepare("update goods set shop_price =:price where goods_id =:id AND goods_name =:name");
        sql.prepare("call update_goods_shopprice(:id, :name, :price)");
        sql.bindValue(":name", name);
        sql.bindValue(":id", id);
        sql.bindValue(":price", price);
        qDebug() << id;
        qDebug() << name;
        qDebug() << price;
        bool addIF = sql.exec();

        if (addIF)
        {
            qDebug() << "修改成功！";
            this->on_pushButton2_search_clicked();
        }
        else
        {
            qDebug() << "修改失败!";
        }
    }
}

// 设置suplier_manage表信息
void mainpage::set_suplier_manage_info()
{
    // 设置表头
    this->dataTableModel->setHorizontalHeaderItem(0, new QStandardItem("供应商id"));
    this->dataTableModel->setHorizontalHeaderItem(1, new QStandardItem("供应商名称"));
    this->dataTableModel->setHorizontalHeaderItem(2, new QStandardItem("供应商简介"));
    this->dataTableModel->setHorizontalHeaderItem(3, new QStandardItem("商品id"));
    this->dataTableModel->setHorizontalHeaderItem(4, new QStandardItem("供应价格"));
    this->dataTableModel->setHorizontalHeaderItem(5, new QStandardItem("供应数量"));
    this->dataTableModel->setHorizontalHeaderItem(6, new QStandardItem("供应时间"));

    // 设置列宽
    ui->shopTable->setColumnWidth(0, 200);
    ui->shopTable->setColumnWidth(1, 200);
    ui->shopTable->setColumnWidth(2, 200);
    ui->shopTable->setColumnWidth(3, 200);
    ui->shopTable->setColumnWidth(4, 200);
    ui->shopTable->setColumnWidth(5, 200);
    ui->shopTable->setColumnWidth(6, 200);
    ui->shopTable->setColumnWidth(7, 200);

    // 设置表格只读属性
    ui->shopTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 最后将设计化的表格，装载在表格上
    ui->shopTable->setModel(this->dataTableModel);
}

// 进货管理
void mainpage::on_actionjinhuo_triggered()
{
    // 切换堆栈窗口下标到3
    ui->stackedWidget->setCurrentIndex(3);
    qDebug() << "已进入进货管理界面";
    QSqlQuery sql;
    //
    sql.prepare("select * from splier_manage_v");
    sql.exec();
    this->dataTableModel->clear();
    this->set_suplier_manage_info();

    int row = 0;        // 定义变量row表示表格行数

    while (sql.next())
    {
        this->dataTableModel->setItem(row, 0, new QStandardItem(sql.value("supplier_id").toString()));
        this->dataTableModel->setItem(row, 1, new QStandardItem(sql.value("supplier_name").toString()));
        this->dataTableModel->setItem(row, 2, new QStandardItem(sql.value("supplier_desc").toString()));
        this->dataTableModel->setItem(row, 3, new QStandardItem(sql.value("goods_id").toString()));
        this->dataTableModel->setItem(row, 4, new QStandardItem(sql.value("market_price").toString()));
        this->dataTableModel->setItem(row, 5, new QStandardItem(sql.value("goods_number").toString()));
        this->dataTableModel->setItem(row, 6, new QStandardItem(sql.value("date").toString()));
        row++;
    }
    sql.clear();
}

bool mainpage::ifSupplier()
{
    QString supplier_id = ui->lineEdit3_suplierID->text();
    QString supplier_name = ui->lineEdit3_suplierName->text();
    QString supplier_desc = ui->lineEdit3_suplierDesc->text();

    QSqlQuery sql;
    //sql.prepare("select * from supplier where supplier_id =:supplier_id and supplier_name =:supplier_name and supplier_desc =:supplier_desc");
    sql.prepare("call ifSupplier_procedure(:supplier_id, :supplier_name)");
    sql.bindValue(":supplier_id", supplier_id);
    sql.bindValue(":supplier_name", supplier_name);
    // sql.bindValue(":supplier_desc", supplier_desc); // 不需要了

    if(sql.exec())
        qDebug() << "执行成功";
    else
        qDebug() << "执行失败";
    sql.next();
    qDebug() << sql.value("supplier_id").toString();
    qDebug() << supplier_id;
    if (supplier_id == sql.value("supplier_id").toString())
    {
        qDebug() << "匹配成功";
        return true;
    }
    else
    {
        qDebug() << "匹配失败";
        return false;
    }
    return true;
}

void mainpage::insertSuplier()
{
    QString supplier_id = ui->lineEdit3_suplierID->text();
    QString supplier_name = ui->lineEdit3_suplierName->text();
    QString supplier_desc = ui->lineEdit3_suplierDesc->text();

    QString goods_id = ui->lineEdit3_goodsID->text();
    QString goods_name = ui->lineEdit3_goodsName->text();
    QString goods_number = ui->lineEdit3_goodsNum->text();

    QString market_price = ui->lineEdit3_marketPrice->text();
    QString shop_price = ui->lineEdit3_shopPrice->text();
    QString goods_desc = ui->lineEdit3_goodsDesc->text();

    QSqlQuery sql;
    //sql.prepare("INSERT INTO splier_manage_v(supplier_id, supplier_name, supplier_desc, goods_id, goods_name, goods_number, market_price, shop_price, goods_desc) VALUES(:supplier_id, :supplier_name, :supplier_desc, :goods_id, :goods_name, :goods_number, :market_price, :shop_price, :goods_desc)");
    sql.prepare("call insert_supplier_procedure(:supplier_id, :supplier_name, :supplier_desc)");

    sql.bindValue(":supplier_id", supplier_id);
    sql.bindValue(":supplier_name", supplier_name);
    sql.bindValue(":supplier_desc", supplier_desc);

    sql.bindValue(":goods_id", goods_id);
    sql.bindValue(":goods_name", goods_name);
    sql.bindValue(":goods_number", goods_number);

    sql.bindValue(":market_price", market_price);
    sql.bindValue(":shop_price", shop_price);
    sql.bindValue(":goods_desc", goods_desc);

    bool insertIF = sql.exec();
    if(insertIF)
    {
        qDebug() << "插入成功！";

    }
    else
    {
        qDebug() << "插入失败=-=！";
    }
}

// 插入到供应管理跟商品中
void mainpage::insertSuppliy_goods()
{
    QString supplier_id = ui->lineEdit3_suplierID->text();
    QString supplier_name = ui->lineEdit3_suplierName->text();
    QString supplier_desc = ui->lineEdit3_suplierDesc->text();

    QString goods_id = ui->lineEdit3_goodsID->text();
    QString goods_name = ui->lineEdit3_goodsName->text();
    QString goods_number = ui->lineEdit3_goodsNum->text();

    QString market_price = ui->lineEdit3_marketPrice->text();
    QString shop_price = ui->lineEdit3_shopPrice->text();
    QString goods_desc = ui->lineEdit3_goodsDesc->text();

    QSqlQuery sql;

    sql.prepare("call insert_suplier_mange_procedure(:supplier_id, :supplier_name, :supplier_desc, :goods_id, :goods_name, :goods_number, :market_price, :shop_price, :goods_desc, :gross, :date)");

    sql.bindValue(":supplier_id", supplier_id);
    sql.bindValue(":supplier_name", supplier_name);
    sql.bindValue(":supplier_desc", supplier_desc);

    sql.bindValue(":goods_id", goods_id);
    sql.bindValue(":goods_name", goods_name);
    sql.bindValue(":goods_number", goods_number);

    sql.bindValue(":market_price", market_price);
    sql.bindValue(":shop_price", shop_price);
    sql.bindValue(":goods_desc", goods_desc);

    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy-MM-dd hh:mm:ss");
    qDebug() << current_date;
    sql.bindValue(":date", current_date);
    // 添加获取价钱的函数
    double price = market_price.toDouble();
    qDebug() << price;
    double gross = goods_number.toInt() * price;
    qDebug() << gross;
    sql.bindValue(":gross", gross);


    if(sql.exec())
    {
        qDebug() <<"进货添加成功！";
    }
    else
    {
        qDebug() <<"进货添加失败!";
    }

}


void mainpage::on_pushButton3_submit_clicked()
{
    // 获取
//    QString supplier_id = ui->lineEdit3_suplierID->text();
//    QString supplier_name = ui->lineEdit3_suplierName->text();
//    QString supplier_desc = ui->lineEdit3_suplierDesc->text();

//    QSqlQuery sql;
//    sql.prepare("select * from supplier where supplier_id =:supplier_id and supplier_name =:supplier_name and supplier_desc =:supplier_desc");
//    sql.bindValue(":supplier_id", supplier_id);
//    sql.bindValue(":supplier_name", supplier_name);
//    sql.bindValue(":supplier_desc", supplier_desc);
    bool supplierIF = this->mainpage::ifSupplier();
    if(supplierIF)
    {
        qDebug() << "该供应商已存在";
        // 插入到 suply_manage
        this->mainpage::insertSuppliy_goods();
    }
    else
    {
        qDebug() << "无该供应商";
        this->mainpage::insertSuplier();
        // 插入到 suplier_manage 视图中
        this->mainpage::insertSuppliy_goods();
    }

}

// 商品结账
void mainpage::on_actionjiezhang_triggered()
{
    // 切换堆栈窗口下标到4
    ui->stackedWidget->setCurrentIndex(4);
    // 显示goods
    qDebug() << "已进入商品结账界面";
    QSqlQuery sql;
    sql.prepare("call look_suply_goods_v()");
    sql.exec();

    this->setgoodsTableInfo();
    this->dataTableModel->setHorizontalHeaderItem(2, new QStandardItem("现有商品个数"));
    this->dataTableModel->setHorizontalHeaderItem(6, new QStandardItem("供应商ID"));

    int row = 0;        // 定义变量row表示表格行数

    while (sql.next())
    {
        this->dataTableModel->setItem(row, 0, new QStandardItem(sql.value("goods_id").toString()));
        this->dataTableModel->setItem(row, 1, new QStandardItem(sql.value("goods_name").toString()));
        this->dataTableModel->setItem(row, 2, new QStandardItem(sql.value("goods_number").toString()));
        this->dataTableModel->setItem(row, 3, new QStandardItem(sql.value("market_price").toString()));
        this->dataTableModel->setItem(row, 4, new QStandardItem(sql.value("shop_price").toString()));
        this->dataTableModel->setItem(row, 5, new QStandardItem(sql.value("goods_desc").toString()));
        this->dataTableModel->setItem(row, 6, new QStandardItem(sql.value("supplier_id").toString()));
        this->dataTableModel->setItem(row, 7, new QStandardItem(sql.value("date").toString()));
        row++;
    }

    sql.clear();

}

bool mainpage::ifgoods(QString id, QString name, QString num)
{
    QSqlQuery sql;
    sql.prepare("select * from suply_goods_v where goods_id =:id and goods_name =:name");
    sql.bindValue(":id", id);
    sql.bindValue(":name", name);
    sql.bindValue(":num", num);
    if(sql.exec())
        qDebug() << "执行成功";
    else
        qDebug() << "执行失败";


    // test code start
//    int row = 0;
//    while (sql.next())
//    {
//        this->dataTableModel->setItem(row, 0, new QStandardItem(sql.value("goods_id").toString()));
//        this->dataTableModel->setItem(row, 1, new QStandardItem(sql.value("goods_name").toString()));
//        this->dataTableModel->setItem(row, 2, new QStandardItem(sql.value("goods_number").toString()));
//        this->dataTableModel->setItem(row, 3, new QStandardItem(sql.value("market_price").toString()));
//        this->dataTableModel->setItem(row, 4, new QStandardItem(sql.value("shop_price").toString()));
//        this->dataTableModel->setItem(row, 5, new QStandardItem(sql.value("goods_desc").toString()));
//        this->dataTableModel->setItem(row, 6, new QStandardItem(sql.value("supplier_id").toString()));
//        this->dataTableModel->setItem(row, 7, new QStandardItem(sql.value("date").toString()));
//        row++;
//    }

    // test end
    sql.next();
    if (num.toInt() <= sql.value("goods_number").toInt())
    {
        qDebug() << num.toInt();
        qDebug() << sql.value("goods_number").toInt();
        qDebug() << "有该商品，并且有足够要求数目的商品";
        return true;
    }
    else
    {
        qDebug() << "匹配失败";
        return false;
    }
    return true;
}

// 更新商品
bool mainpage::update_goods_num(QSqlQuery sql, QString id, QString name, QString num)
{
    //QSqlQuery sql;
    sql.prepare("call update_goods_num(:id, :name, :num)");
    sql.bindValue(":id", id);
    sql.bindValue(":name", name);
    int num1 = num.toInt();
    sql.bindValue(":num", num1);
    if(sql.exec())
    {
        qDebug() << "执行成功";
        return true;
    }
    else
    {
        qDebug() << "执行失败";
        return false;
    }
    return true;
}

// 查找id
double mainpage::search_goods_price(QString gid)
{
    qDebug() <<"进入查找id界面";
    QSqlQuery sql;
    sql.prepare("select * from goods where goods_id =:gid");
    sql.bindValue(":gid", gid);
    if(sql.exec())
    {
        qDebug() << "执行成功";
    }
    else
    {
        qDebug() << "执行失败";
    }
    sql.next();
    double price = sql.value("shop_price").toDouble();
    qDebug() << price;
    return price;
}

// 添加销售记录
bool mainpage::insert_sales_manage(QSqlQuery sql, QString sid, QString gid, QString name, QString num)
{
    //QSqlQuery sql;
    sql.prepare("call insert_sales_manage(:sid, :gid, :name, :num, :date, :gross)");
    sql.bindValue(":sid", sid);
    sql.bindValue(":gid", gid);
    sql.bindValue(":name", name);
    int num1 = num.toInt();
    sql.bindValue(":num", num1);
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy-MM-dd hh:mm:ss");
    qDebug() << current_date;
    sql.bindValue(":date", current_date);
    // 添加获取价钱的函数
    double price = mainpage::search_goods_price(gid);
    qDebug() << price;
    double gross = num.toInt() * price;
    qDebug() << gross;
    sql.bindValue(":gross", gross);
    if(sql.exec())
    {
        qDebug() << "添加销售记录，添加成功！";
        return true;
    }
    else
    {
        qDebug() << "添加销售记录失败！";
        return false;
    }
    return true;
}

// 售卖按钮
void mainpage::on_pushButton4_sale_clicked()
{
    QString id = ui->lineEdit4_goodsid->text();
    QString name = ui->lineEdit4_goodsname->text();
    QString num = ui->lineEdit4_goods_num->text();
    QString salesid = ui->lineEdit4_salesid->text();


    // sql.exec("start teansaction");
    // 判断有无相应产品 判断有无足够产品

    if(QSqlDatabase::database().driver()->hasFeature(QSqlDriver::Transactions))
    {
        //先判断该数据库是否支持事务操作
        if(QSqlDatabase::database().transaction()) //启动事务操作
        {
            QSqlQuery sql;
            bool IF = ifgoods(id, name, num);
            if(IF)
            {
                qDebug() <<"开始更新";
                if(update_goods_num(sql, id, name, num))
                {
                    qDebug() << "更新成功";
                    qDebug() << "开始添加";
                    if(insert_sales_manage(sql, salesid, id, name, num))
                    {
                         qDebug() <<"添加成功";
                         if(!QSqlDatabase::database().commit())
                         {
                             qDebug() << QSqlDatabase::database().lastError(); //提交
                             if(!QSqlDatabase::database().rollback())
                             {
                                 qDebug() << QSqlDatabase::database().lastError(); //回滚
                             }
                             else
                             {
                                 qDebug() << "二阶段事务貌似提交成功";
                             }
                         }
                         else
                         {
                             qDebug() << "一阶段事务貌似提交成功";
                         }
                    }
                    else
                    {
                        qDebug() << "添加失败";
                        // sql.exec("ROLLBACK");
                    }
                }
            }
        }
    }
}

void mainpage::setsales_manageTaleInfo()
{
    // 清理先前的表格
    this->dataTableModel->clear();
    // 设置表头
    this->dataTableModel->setHorizontalHeaderItem(0, new QStandardItem("销售id"));
    this->dataTableModel->setHorizontalHeaderItem(1, new QStandardItem("商品id"));
    this->dataTableModel->setHorizontalHeaderItem(2, new QStandardItem("商品名称"));
    this->dataTableModel->setHorizontalHeaderItem(3, new QStandardItem("商品个数"));
    this->dataTableModel->setHorizontalHeaderItem(4, new QStandardItem("日期"));
    this->dataTableModel->setHorizontalHeaderItem(5, new QStandardItem("总价钱"));

    // 设置列宽
    ui->shopTable->setColumnWidth(0, 200);
    ui->shopTable->setColumnWidth(1, 200);
    ui->shopTable->setColumnWidth(2, 200);
    ui->shopTable->setColumnWidth(3, 200);
    ui->shopTable->setColumnWidth(4, 200);
    ui->shopTable->setColumnWidth(5, 500);



    // 设置表格只读属性
    ui->shopTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 最后将设计化的表格，装载在表格上
    ui->shopTable->setModel(this->dataTableModel);
}

void mainpage::on_actiontongji_triggered()
{
    ui->stackedWidget->setCurrentIndex(5);
    qDebug("进入销售统计页面");
    this->setsales_manageTaleInfo();

    QSqlQuery sql;
    if(sql.exec("call look_sales_manage()"))
    {
        qDebug("展开所有销售统计成功");
        int row = 0;        // 定义变量row表示表格行数

        while (sql.next())
        {
            this->dataTableModel->setItem(row, 0, new QStandardItem(sql.value("sales_id").toString()));
            this->dataTableModel->setItem(row, 1, new QStandardItem(sql.value("goods_id").toString()));
            this->dataTableModel->setItem(row, 2, new QStandardItem(sql.value("goods_name").toString()));
            this->dataTableModel->setItem(row, 3, new QStandardItem(sql.value("goods_number").toString()));
            this->dataTableModel->setItem(row, 4, new QStandardItem(sql.value("date").toString()));
            this->dataTableModel->setItem(row, 5, new QStandardItem(sql.value("gross_price").toString()));
            row++;
        }
        sql.clear();
    }
    else
    {
        qDebug() << "展开销售统计失败";
    }

}

void mainpage::on_pushButton5_submit_clicked()
{
    qDebug() << "销售统计提交按钮";
    this->setsales_manageTaleInfo();

    QSqlQuery sql;
    QString sid = ui->lineEdit5_saleid->text();
    if(sid == "")
    {
        if(sql.exec("call look_sales_manage()"))
        {
            qDebug("展开所有销售统计成功");
            int row = 0;        // 定义变量row表示表格行数

            while (sql.next())
            {
                this->dataTableModel->setItem(row, 0, new QStandardItem(sql.value("sales_id").toString()));
                this->dataTableModel->setItem(row, 1, new QStandardItem(sql.value("goods_id").toString()));
                this->dataTableModel->setItem(row, 2, new QStandardItem(sql.value("goods_name").toString()));
                this->dataTableModel->setItem(row, 3, new QStandardItem(sql.value("goods_number").toString()));
                this->dataTableModel->setItem(row, 4, new QStandardItem(sql.value("date").toString()));
                this->dataTableModel->setItem(row, 5, new QStandardItem(sql.value("gross_price").toString()));
                row++;
            }
            sql.clear();
        }
        else
        {
            qDebug() << "展开销售统计失败";
        }
    }
    else
    {
        sql.prepare("call search_sales_manage(:sid)");
        sql.bindValue(":sid", sid);
        if(sql.exec())
        {
            qDebug() << "查询特定销售记录成功";
            int row = 0;        // 定义变量row表示表格行数
            while (sql.next())
            {
                this->dataTableModel->setItem(row, 0, new QStandardItem(sql.value("sales_id").toString()));
                this->dataTableModel->setItem(row, 1, new QStandardItem(sql.value("goods_id").toString()));
                this->dataTableModel->setItem(row, 2, new QStandardItem(sql.value("goods_name").toString()));
                this->dataTableModel->setItem(row, 3, new QStandardItem(sql.value("goods_number").toString()));
                this->dataTableModel->setItem(row, 4, new QStandardItem(sql.value("date").toString()));
                this->dataTableModel->setItem(row, 5, new QStandardItem(sql.value("gross_price").toString()));
                row++;
            }
            sql.clear();
        }
        else
        {
            qDebug() << "展开特定销售统计失败";
        }
    }
}

// 注册用户提交
void mainpage::on_pushButton0_submit_clicked()
{
    QString account = ui->lineEdit0_account->text();
    QString password = ui->lineEdit0_password->text();
    QString username = ui->lineEdit0_username->text();
    QString type = ui->lineEdit0_usertype->text();

    QSqlQuery sql;
    sql.prepare("call insert_m_info(:account, :password, :username, :type)");

    sql.bindValue(":account", account);
    sql.bindValue(":password", password);
    sql.bindValue(":username", username);
    sql.bindValue(":type", type);

    if(sql.exec())
    {
        this->on_umaction_triggered();
        qDebug() << "已注册";
    }
    else
    {
        qDebug() << "注册失败";
    }
}

// 数据备份
void mainpage::on_pushButton6_backup_clicked()
{
//    QSqlQuery sql;
//    if(sql.exec("mysqldump -u root -h localhost -p shopmanagement>D:\shopmanagesys_Backup.sql"))
//    {
//        qDebug() << "备份成功";
//    }
//    else
//    {
//        qDebug() << "备份失败";
//    }
    qDebug() << "备份成功";
    QProcess p(this);
    p.setWorkingDirectory("D:\mysql\bin");//切换工作目录
    p.setProgram("cmd");
    QStringList argument;
    argument<<"mysqldump -hlocalhost -uroot -p123456 -t shopmanagement>D:\shopback_up.sql";//若没有没有where条件， 有where调价， 可以把命令存储到bat脚本，然后运行脚本。因为QProcess 不支持 引号，
    p.setArguments(argument);
    p.start();
    p.waitForStarted(); //等待程序启动
    p.waitForFinished();//等待程序关闭
    p.close();
    msgBox = new QMessageBox("title",		///--这里是设置消息框标题
            "messageBox comment",						///--这里是设置消息框显示的内容
            QMessageBox::Critical,							///--这里是在消息框显示的图标
            QMessageBox::Ok | QMessageBox::Default,		///---这里是显示消息框上的按钮情况
            QMessageBox::Cancel | QMessageBox::Escape,	///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
            0);														///---这里是 定义第三个按钮， 该例子 只是 了显示2个按钮

    msgBox->show();


}

void mainpage::on_action_backup_triggered()
{
    ui->stackedWidget->setCurrentIndex(6);
}
