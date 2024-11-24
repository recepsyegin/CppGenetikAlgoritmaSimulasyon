1. Problem Tanımı
Amaç, önceden belirlenmiş bir hedef diziyi (örneğin, "GitHub") eşleştirecek bir çözüm bulmaktır. Genetik Algoritma, rastgele başlatılarak çözüme gider (fitness değerlerine göre)

2. Kavram
Rastgele Başlangıç: Rastgele karakterlerden oluşan bir dizi popülasyonu üretilir.
Fitness Değerlendirmesi: Her birey, hedef dizeye ne kadar yakın olduğuna göre değerlendirilir.
Seçim: En uygun bireyler üreme için seçilir.
Çaprazlama: İki ebeveyn birey, yeni çocuk bireyler oluşturmak için birleştirilir.
Mutasyon: Çeşitliliği sağlamak için rastgele değişiklikler yapılır.

4. Kod
Genler: Dizeleri oluşturan karakterler.
Kromozom: Aday çözüm (bir birey).
Fitness Fonksiyonu: Bir bireyin hedefe ne kadar yakın olduğunu ölçer.
Popülasyon: Bir grup kromozom (birey).
Evrim Süreci: Algoritma, her nesilde popülasyonu iyileştirerek çalışır.
Proje Akışı
Hedef Diziyi Belirleyin: Çözülmek istenen hedef dizeyi kodda belirtin (örneğin, "hello").
Başlangıç Popülasyonunu Üretin: Rastgele dizeler oluşturun.
Tekrarlanan Süreç:
Her bireyin uygunluk (fitness) değeri hesaplanır.
Üreme için en uygun bireyleri seçilir.
Çaprazlama ve mutasyon uygulayarak yeni bireyler üretilir
Hedef dize bulunana kadar veya maksimum nesil sayısına ulaşılana kadar işlem tekrarlanır.
Sonuç: Her nesilde en iyi birey ve uygunluk değeri ekrana yazdırılır. Hedef dize bulunduğunda işlem durur.
