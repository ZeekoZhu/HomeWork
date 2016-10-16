

/// <reference path='./typings/index.d.ts' />


/**
 * Resource
 */
class Resource {
    constructor(
        protected isDebug: boolean = false,
        protected prefix: string = ''
    ) {
    }
}

interface AccountLoginRequestModel {
}
class Account extends Resource {
    constructor(isDebug?: boolean, prefix?: string) {
        super(isDebug, prefix);
    }
    public Login(
        data?: AccountLoginRequestModel,
        success?: (data: AccountLoginResponseModel, textStatus: string, jqXHR: JQueryXHR) => any,
        error?: (jqXHR: JQueryXHR, textStatus: string, errorThrown: string) => any,
        complete?: (jqXHR: JQueryXHR, textStatus: string) => any
    ) {
        let _this = this;
        $.ajax({
            url: _this.prefix + 'api/Account/Login',
            method: 'POST',
            contentType: 'application/json',
            data: data,
            success: success,
            error: error,
            complete: complete
        });
    }
}
interface ValuesGetRequestModel {
}
interface ValuesGetRequestModel {
}
interface ValuesPostRequestModel {
}
interface ValuesPutRequestModel {
}
interface ValuesDeleteRequestModel {
}
class Values extends Resource {
    constructor(isDebug?: boolean, prefix?: string) {
        super(isDebug, prefix);
    }
    public Get(
        data?: ValuesGetRequestModel,
        success?: (data: ValuesGetResponseModel, textStatus: string, jqXHR: JQueryXHR) => any,
        error?: (jqXHR: JQueryXHR, textStatus: string, errorThrown: string) => any,
        complete?: (jqXHR: JQueryXHR, textStatus: string) => any
    ) {
        let _this = this;
        $.ajax({
            url: _this.prefix + 'api/Values/Get',
            method: '',
            contentType: 'application/json',
            data: data,
            success: success,
            error: error,
            complete: complete
        });
    }
    public Get(
        data?: ValuesGetRequestModel,
        success?: (data: ValuesGetResponseModel, textStatus: string, jqXHR: JQueryXHR) => any,
        error?: (jqXHR: JQueryXHR, textStatus: string, errorThrown: string) => any,
        complete?: (jqXHR: JQueryXHR, textStatus: string) => any
    ) {
        let _this = this;
        $.ajax({
            url: _this.prefix + 'api/Values/Get',
            method: '',
            contentType: 'application/json',
            data: data,
            success: success,
            error: error,
            complete: complete
        });
    }
    public Post(
        data?: ValuesPostRequestModel,
        success?: (data: ValuesPostResponseModel, textStatus: string, jqXHR: JQueryXHR) => any,
        error?: (jqXHR: JQueryXHR, textStatus: string, errorThrown: string) => any,
        complete?: (jqXHR: JQueryXHR, textStatus: string) => any
    ) {
        let _this = this;
        $.ajax({
            url: _this.prefix + 'api/Values/Post',
            method: 'POST',
            contentType: 'application/json',
            data: data,
            success: success,
            error: error,
            complete: complete
        });
    }
    public Put(
        data?: ValuesPutRequestModel,
        success?: (data: ValuesPutResponseModel, textStatus: string, jqXHR: JQueryXHR) => any,
        error?: (jqXHR: JQueryXHR, textStatus: string, errorThrown: string) => any,
        complete?: (jqXHR: JQueryXHR, textStatus: string) => any
    ) {
        let _this = this;
        $.ajax({
            url: _this.prefix + 'api/Values/Put',
            method: '',
            contentType: 'application/json',
            data: data,
            success: success,
            error: error,
            complete: complete
        });
    }
    public Delete(
        data?: ValuesDeleteRequestModel,
        success?: (data: ValuesDeleteResponseModel, textStatus: string, jqXHR: JQueryXHR) => any,
        error?: (jqXHR: JQueryXHR, textStatus: string, errorThrown: string) => any,
        complete?: (jqXHR: JQueryXHR, textStatus: string) => any
    ) {
        let _this = this;
        $.ajax({
            url: _this.prefix + 'api/Values/Delete',
            method: '',
            contentType: 'application/json',
            data: data,
            success: success,
            error: error,
            complete: complete
        });
    }
}

interface User {
    UserId: number;
    UserName: string;
    Password: string;
    AuthToken: string;
    AuthExpire?: number;
    RefreshToken: string;
    RefreshExpire?: number;
    Fuck: FuckClass;
    Fucked: number;
}
interface FuckClass {
    UserId: number;
    UserName: string;
}

 

