public class foo {
  static {
    System.loadLibrary("boo");
  }

  public static class FooClass {
    public int a;
    public int b;
  }

  public static void main(String[] args) {
     FooClass foo = new FooClass();
     new foo().sayHello(foo);
     System.out.println(foo.a);
     System.out.println(foo.b);
  }

  private native void sayHello(FooClass foo);
}