class Employee:

    available = True
    supervisor = None

    def connect(self, call):
        if not self.available:
            if not self.supervisor:
                return False
            return self.supervisor.connect(call)
        self.available = False
        return True


class Director(Employee):

    supervisor = None


class Manager(Employee):

    supervisor = Director()


class Dispatcher(Employee):

    supervisor = Manager()


class CallCenter:

    employees = []

    def add_employee(self):
        self.employees.append(Employee())

    def dispatch_call(self, call):
        connected = False
        i = 0
        while not connected and i < len(self.employees):
            connected = self.employees[i].connect(call)
            i += 1
        return connected


def test_one_call_center():
    hitech = CallCenter()

    assert not hitech.dispatch_call("no employees, should return fail")

    hitech.add_employee()
    assert hitech.dispatch_call("hej first employee")
    assert hitech.dispatch_call("hej manager")
    assert hitech.dispatch_call("hej director")
    assert not hitech.dispatch_call("I think you are all busy")


def test_two_call_centers():
    hitech = CallCenter()

    assert not hitech.dispatch_call("no employees, should return fail")

    hitech.add_employee()
    assert hitech.dispatch_call("hej first employee")

    lowtech = CallCenter()

    assert not lowtech.dispatch_call("no employees, should return fail")

    lowtech.add_employee()
    assert lowtech.dispatch_call("hej first employee")

