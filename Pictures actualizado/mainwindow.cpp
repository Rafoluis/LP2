#include "mainwindow.h"
#include "ui_mainwindow.h"


void save_list(linked_list<pict >&vt,const char * file)
{
    /*ofstream of(file,ios::binary);
    size_t size_v;
    for(linked_list<pict>::iterator i=vt.begin();i!=vt.end();++i){
        size_v=(*i).show_name().size();
        of.write((char*)&size_v,sizeof(size_t));
        of.write((*i).show_name().c_str(),size_v);
    }*/
    ofstream archivo;
    archivo.open(file,ios::out);
    archivo.clear();
    for(linked_list<pict >::iterator it=vt.begin();it!=vt.end();++it){
        archivo<<(*it).show_name()<<endl;
        archivo<<(*it).show_file()<<endl;
    }
    archivo.close();
}

void load_list(linked_list<pict >&vt,const char * file)
{


    /*ifstream ifs(file,ios:: binary);
    pict s;
    char * vt_b;
    size_t size_v;
    while(ifs.read((char*)&size_v, sizeof(int))){
        vt_b=new char[size_v + 1];
        ifs.read(vt_b,size_v);
        vt_b[size_v]=0;
        s.show_name()=vt_b;
        vt.push_back(s);
    }*/
    ifstream ifs;
    ifs.open(file,ios::in);
    pict a;
    string s;
    getline(ifs,s);
    while(s!=""){
        a.add_name(s);
        getline(ifs,s);
        a.add_file(s);
        vt.push_back(a);
        getline(ifs,s);
    }
    ifs.close();

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pict img1("Verde","C:/Users/JoseRafael/Desktop/Pictures/pictures/descarga");
    //img1.add_tag("Paisaje");
    //img1.add_tag("Verde");
    pict img2("Ciudad","C:/Users/JoseRafael/Desktop/Pictures/pictures/descarga2");
    //img2.add_tag("Ciudad");
    //img2.add_tag("Paisaje");
    pict img3("Arte","C:/Users/JoseRafael/Desktop/Pictures/pictures/descarga3");
    //img3.add_tag("Arte");
    pict img4("Arcoiris","C:/Users/JoseRafael/Desktop/Pictures/pictures/descarga4");
    //img4.add_tag("Arcoiris");
    /*pictures.push_back(img1);
    pictures.push_back(img2);
    pictures.push_back(img3);
    pictures.push_back(img4);
    */
    load_list(pictures,"C:/Users/JoseRafael/Desktop/Pictures/pictures/file.txt");
    it=pictures.begin();
    text=(*it).show_all();

    a=new char[text.size()];
    a[text.size()]=0;
    for(size_t i=0;i<text.size();i++){
        a[i]=text[i];
    }
    ui->label_txt->setText(a);
    it=pictures.begin();
    string txt=(*it).show_file();
    a=new char[txt.size()];
    a[txt.size()]=0;
    for(size_t i=0;i<txt.size();i++){
        a[i]=txt[i];
    }
    pix={a};
    ui->label_picture->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    save_list(pictures,"C:/Users/JoseRafael/Desktop/Pictures/pictures/file.txt");
    delete ui;
    delete a;
}

void MainWindow::on_pushButton_2_clicked()
{
    ++it;
    if(it!=pictures.end()){

    }
    else{
        it=pictures.begin();
    }
    text=(*it).show_all();
    a=new char[text.size()];
    a[text.size()]=0;
    for(size_t i=0;i<text.size();i++){
        a[i]=text[i];
    }
    ui->label_txt->setText(a);
    string txt=(*it).show_file();
    a=new char[txt.size()];
    a[txt.size()]=0;
    for(size_t i=0;i<txt.size();i++){
        a[i]=txt[i];
    }
    pix={a};
    ui->label_picture->setPixmap(pix);

}

void MainWindow::on_pushButton_clicked()
{
    if(it!=pictures.begin()){
        --it;
    }
    else{
        it=pictures.last();
    }
    text=(*it).show_all();
    a=new char[text.size()];
    a[text.size()]=0;
    for(size_t i=0;i<text.size();i++){
        a[i]=text[i];
    }
    ui->label_txt->setText(a);
    string txt=(*it).show_file();

    a=new char[txt.size()];
    a[txt.size()]=0;
    for(size_t i=0;i<txt.size();i++){
        a[i]=txt[i];
    }
    pix={a};
    ui->label_picture->setPixmap(pix);

}


void MainWindow::on_pushButton_3_clicked()
{
    QString new_name=ui->textEdit_name->toPlainText();
    QString new_file=ui->textEdit_file->toPlainText();
    string  nn = new_name.toStdString();
    string  nf = new_file.toStdString();
    a=new char[nn.size()];
    a[nn.size()]=0;
    for(size_t i=0;i<nn.size();i++){
        a[i]=nn[i];
    }
    char*b=new char[nf.size()];
    b[nf.size()]=0;
    for(size_t i=0;i<nf.size();i++){
        b[i]=nf[i];
    }
    pict new_img(a,b);

    pictures.push_back(new_img);

}
