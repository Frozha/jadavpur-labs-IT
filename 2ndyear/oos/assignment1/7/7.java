

abstract class Publication{
        int noOfPages;
        float price;
        String publisherName;
        Publication(int noOfPages, float price, String publisherName){
                this.noOfPages = noOfPages;
                this.price = price;
                this.publisherName = publisherName;
        }
        void show(){
                System.out.println("pages : "+noOfPages);
                System.out.println("cost : "+ price);
                System.out.println("publisher : "+publisherName);
                System.out.println("-------------------------------");
        }
}

class Book extends Publication{
        String title;
        Book(String title ,int noOfPages, float price, String publisherName){
                super(noOfPages, price, publisherName);
                this.title = title;
        }
        @Override void show(){
        System.out.println("title : "+title);
        super.show();
        }
}

class Journal extends Publication{
        Journal(int noOfPages, float price, String publisherName){
                super(noOfPages, price, publisherName);
        }
}

class Main{
        public static void main(String[] a){
                Publication[] library = new Publication[5];
                for(int i=0;i<3;i++){
                        library[i] = new Book("title"+(i+1),500*(i+1),201.5f*(i+1),"author"+(i+1));
                }
                for(int i=0;i<2;i++){
                        library[i+3] = new Journal(500*(i+1),201.5f*(i+1),"author"+(i+1));
                }
                for(Publication a1 : library){
                        a1.show();
                }
        }
}

