class game menerapkan observer pattern untuk mendraw, mengupdate setiap object yang menjadi turunan kelas object

class Factory menerapkan flyweight pattern dimana kelas ini digunakan untuk memperoleh parameter untuk object enemy dan obstacle.s
	pertama kelas ini akan menginisialisasi paramter untuk enemy dan obstacle. setelah inisialisasi, setiap akan membuat parameter untuk enemy atau obstacle, kelas ini akan dipanggil dengan method getParams dengan parameter type.
jika type sesuai dengan inisialisasi parameter maka akan mengembalikan object yang sudah terinisialisasi menjadi parameter baru untuk enemy atau obstacle.

class GameObjectStore (Storage) menerapkan factory pattern dimana kelas ini akan membuat object baru sesuai dengan game object atau turunan dari game object dimana turunan tersebut adalah enemy dan obstacle.
ketika object baru ingin dibuat maka akan memanggil kelas ini dengan memanggil fungsi createObject dengan parameter yang didapat dari class Factory