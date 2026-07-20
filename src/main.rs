use std::sync::{Arc, Condvar, Mutex, RwLock};
use std::thread;

fn some_func(lock: Arc<Mutex<u64>>) {
    loop {
        let mut val = lock.lock().unwrap();
        *val += 1;
        println!("{}", *val);
    }
}

fn child(id: u64, p: Arc<(Mutex<bool>, Condvar)>) {
    let &(ref lock, ref cvar) = &*p;

    let mut started = lock.lock().unwrap();
    while !*started {
        started = cvar.wait(started).unwrap();
    }
    //cvar.wait_while(started, |started| !*started).unwrap();
    println!("child {}", id);
}

fn parent(p: Arc<(Mutex<bool>, Condvar)>) {
    let &(ref lock, ref cvar) = &*p;
    let mut started = lock.lock().unwrap();
    *started = true;
    cvar.notify_all();
    println!("parent");
}

//fn main() {
//    //let lock0 = Arc::new(Mutex::new(0));
//    //let lock1 = lock0.clone();
//
//    //let th0 = thread::spawn(move || {
//    //    some_func(lock0);
//    //});
//
//    //let th1 = thread::spawn(move || {
//    //    some_func(lock1);
//    //});
//
//    //th0.join().unwrap();
//    //th1.join().unwrap();
//
//    let pair0 = Arc::new((Mutex::new(false), Condvar::new()));
//    let pair1 = pair0.clone();
//    let pair2 = pair0.clone();
//
//    let c0 = thread::spawn(move || child(0, pair0));
//    let c1 = thread::spawn(move || child(1, pair1));
//    let p = thread::spawn(move || parent(pair2));
//
//    c0.join().unwrap();
//    c1.join().unwrap();
//    p.join().unwrap();
//}

fn main() {
    let lock = RwLock::new(10);
    {
        let v1 = lock.read().unwrap();
        let v2 = lock.read().unwrap();
        println!("v1 = {}", v1);
        println!("v2 = {}", v2);
    }

    {
        let mut v = lock.write().unwrap();
        *v = 7;
        println!("v = {}", v);
    }
}
