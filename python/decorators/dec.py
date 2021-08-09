# def div(a,b):
#     print(a/b)

def smart_div(func):
    def inner(a,b):
        if a<b:
            a,b=b,a
        return func(a,b)
    return inner
@smart_div
def div(a,b):
    print(a/b)

#div = smart_div(div)

div(5,4)