#define echoPin 12 //Ultrasonik sensörün echo pini Arduino'nun 12.pinine
#define trigPin 13 //Ultrasonik sensörün trig pini Arduino'nun 13.pinine tanımlandı.
#define motorA1 3
#define motorA2 5
#define motorB1 6
#define motorB2 9


int Hiz=150;


long sure, uzaklik; //süre ve uzaklık diye iki değişken tanımlıyoruz.

void setup() {


  // ultrasonik sensör Trig pininden ses dalgaları gönderdiği için OUTPUT (Çıkış),
  // bu dalgaları Echo pini ile geri aldığı için INPUT (Giriş) olarak tanımlanır.
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  pinMode(motorA1 , OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT); //Motorlarımızı çıkış olarak tanımlıyoruz.
  pinMode(motorB2, OUTPUT);
 


  Serial.begin(9600);

}

void loop() {


  digitalWrite(trigPin, LOW); //sensör pasif hale getirildi
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); //Sensore ses dalgasının üretmesi için emir verildi
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); //Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi

  sure = pulseIn(echoPin, HIGH); //ses dalgasının geri dönmesi için geçen sure ölçülüyor
  uzaklik = sure / 29.1 / 2; //ölçülen süre uzaklığa çevriliyor

  Serial.println(uzaklik);

  if (uzaklik < 15) // Uzaklık 15'den küçük ise,
  {
    geri();  // 150 ms geri git
    delay(150);
    sag();  // 250 ms sağa dön
    delay(250);
  }
  else {  // değil ise,
    ileri(); // ileri git
  }

}
void ileri(){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.

  analogWrite(motorA1, Hiz); 
  analogWrite(motorA2, 0);
  analogWrite(motorB1, Hiz);   
  analogWrite(motorB2, 0); 

}
void sag(){ // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.

 analogWrite(motorA1, Hiz);  
 analogWrite(motorA2, 0); 
 analogWrite(motorB1, 0); 
 analogWrite(motorB2, 0); 
  
  
}
void geri(){ // Robotun geri yönde hareketi için fonksiyon tanımlıyoruz.

    analogWrite(motorA1, 0);  
    analogWrite(motorA2, Hiz); 
    analogWrite(motorB1, 0); 
    analogWrite(motorB2, Hiz); 
  
}
