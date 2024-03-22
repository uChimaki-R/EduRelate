#include "widget.h"
#include "ui_widget.h"
#include "func.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("C++单词拼装器\t(20222131003 陈锐)");
    connect(ui->path, &QTextBrowser::textChanged, this, &Widget::chose_file_path);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_choose_btn_clicked()
{
    // 选择文件
    QString fileName = QFileDialog::getOpenFileName(this, "选择一个文件", QCoreApplication::applicationFilePath(), "*.cpp");
    if(!fileName.isEmpty()){
        ui->path->setText(fileName);
    }
    else{
        ui->path->setText("请选择一个cpp文件");
    }
}

void Widget::on_run_btn_clicked()
{
    QString file_path = ui->path->toPlainText();
    QFile fp(file_path);
    if(!fp.open(QFile::ReadOnly)){
        QMessageBox::warning(this, "警告", "请选择正确的文件路径后再次尝试");
        return;
    }
    QString output_string = QString::fromStdString(do_assembly(file_path.toStdString()));
    ui->result->setText(output_string);
}

void Widget::chose_file_path()
{
    QString file_path = ui->path->toPlainText();
    QFile fp(file_path);
    if(!fp.open(QFile::ReadOnly)){
        QMessageBox::warning(this, "警告", "请选择正确的文件路径后再次尝试");
        return;
    }
    else{
        QByteArray ba = fp.readAll();
        ui->content->setText(ba);
    }
}
