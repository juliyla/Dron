Sruba::Sruba(){
 double podstawa=0;
 double wysokosc=0;
}

void Sruba::ObrotS(double kat){
    double i;
    for(i=0;i<=kat;i+=0,1){
        (*this).ObrotG(0,1);
    }
    (*this).ObrotG(0,1*(1-((i-kat)/0,1)));    
}